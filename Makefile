EXECUTABLE = run
TEAM_ID = abc
ZIP_NAME = $(strip $(TEAM_ID))

COMPILER ?= $(GCC_PATH)gcc
ifdef DEBIG
FLAGS ?= -O0 -ggdb -Wall -Wextra $(GCC_SUPPFLAGS)
else
FLAGS ?= -O3 -Wall -Wextra $(GCC_SUPPFLAGS)
endif
LIBS = -lpthread

SRCS=$(wildcard src/*.c)

release: $(SRCS)
	$(COMPILER) $(FLAGS) -o $(EXECUTABLE) $(LIBS) $^

zip: dist-clean
	zip $(ZIP_NAME).zip -r ./

submit: zip
	curl -F "file=@$(ZIP_NAME).zip" -L http://intel-software-academic-program.com/ayc-upload/upload.php

clean:
	-rm -f *.o
	-rm -f $(EXECUTABLE)
	-rm -f *.zip

