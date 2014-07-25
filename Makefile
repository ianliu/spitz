SUBDIRS = spitz examples

all clean test:
	@for dir in $(SUBDIRS); do \
	  $(MAKE) -C $$dir $@; \
	done

install:
	@$(MAKE) -C spitz $@
