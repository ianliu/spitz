/*
 * Copyright 2014 Ian Liu Rodrigues <ian.liu@ggaunicamp.com>
 *
 * This file is part of spitz.
 *
 * spitz is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * spitz is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with spitz.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef __SPITZ_CPP__
#define __SPITZ_CPP__

#include <spitz/stream.hpp>

namespace spitz {
  class jobmanager {
    public:
      virtual bool next_task(stream& stream) = 0;
  };

  class worker {
    public:
      virtual void run(stream& task, stream& result) = 0;
  };

  class committer {
    public:
      virtual void commit_task(stream& result) = 0;
      virtual void commit_job(stream& final_result) {
        (void)(final_result);
      }
  };

  class factory {
    public:
      virtual jobmanager *create_jobmanager(int, char **) = 0;
      virtual worker *create_worker(int, char **) = 0;
      virtual committer *create_committer(int, char **) = 0;
  };
};

extern spitz::factory *spitz_factory;

extern "C" void *spits_job_manager_new(int argc, char *argv[])
{
  spitz::jobmanager *jm = spitz_factory->create_jobmanager(argc, argv);
  return reinterpret_cast<void*>(jm);
}

extern "C" int spits_job_manager_next_task(void *user_data, struct byte_array *ba)
{
  class spitz::jobmanager *jm = reinterpret_cast<spitz::jobmanager*>(user_data);
  spitz::stream task(ba);
  return jm->next_task(task) ? 1 : 0;
}

extern "C" void *spits_worker_new(int argc, char **argv)
{
  spitz::worker *w = spitz_factory->create_worker(argc, argv);
  return reinterpret_cast<void*>(w);
}

extern "C" void spits_worker_run(void *user_data, struct byte_array *task, struct byte_array *result)
{
  spitz::worker *w = reinterpret_cast<spitz::worker*>(user_data);
  spitz::stream _task(task);
  spitz::stream _result(result);
  w->run(_task, _result);
}

extern "C" void *spits_setup_commit(int argc, char *argv[])
{
  spitz::committer *co = spitz_factory->create_committer(argc, argv);
  return reinterpret_cast<void*>(co);
}

extern "C" void spits_commit_pit(void *user_data, struct byte_array *result)
{
  spitz::committer *co = reinterpret_cast<spitz::committer*>(user_data);
  spitz::stream _result(result);
  co->commit_task(_result);
}

extern "C" void spits_commit_job(void *user_data, struct byte_array *final_result)
{
  spitz::committer *co = reinterpret_cast<spitz::committer*>(user_data);
  spitz::stream _final_result(final_result);
  co->commit_job(_final_result);
}

#endif /* __SPITZ_CPP__ */

// vim:ft=cpp:sw=2:et:sta
