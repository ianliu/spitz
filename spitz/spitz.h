#ifndef __SPITZ_CPP__
#define __SPITZ_CPP__

namespace spitz {
  class JobManager {
    public:
      virtual void setup(int argc, char *argv[]) {};
      virtual bool next_task(Stream& stream) = 0;
  };

  class Worker {
    public:
      virtual void setup(int argc, char *argv[]) {};
      virtual void run(const Stream& task, Stream& result) = 0;
  };

  class Committer {
    public:
      virtual void setup(int argc, char *argv[]) {};
      virtual void commit_task(const Stream& result) = 0;
      virtual void commit_job(Stream& final_result) {};
  };
};

#endif /* __SPITZ_CPP__ */

// vim:ft=cpp:sw=2:et:sta
