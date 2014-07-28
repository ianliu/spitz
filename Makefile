SUBDIRS = spitz examples

all clean test install:
	@for dir in $(SUBDIRS); do \
	  $(MAKE) -C $$dir $@; \
	done
