.PHONY: clean all

PROCESSOR_ARCHITECTURE := $(shell arch)
ifeq ($(PROCESSOR_ARCHITECTURE),arm64)
	CC := x86_64-linux-gnu-gcc-11
else ifeq ($(PROCESSOR_ARCHITECTURE),aarch64)
	CC := x86_64-linux-gnu-gcc-11
else
	CC := gcc
endif

ASMFLAGS := -fno-asynchronous-unwind-tables -fno-stack-protector -fcf-protection=none -fomit-frame-pointer -no-pie -fno-pic
NOOPTFLAGS := -O0
OPTFLAGS := -O1
DEBUGFLAGS := -g

all: msg q2 q2.s

q%: q%.c
	$(CC) $(NOOPTFLAGS) $(ASMFLAGS) $^ -o $@

q%.s: q%.c
	$(CC) $(NOOPTFLAGS) $(ASMFLAGS) $^ -S -o $@

clean:
	rm q2 q2.s

msg:
ifeq ($(PROCESSOR_ARCHITECTURE),arm64)
	@echo "Apple Silicon machine detected."
	@echo "Please run inside the course container and look at README.apple!"
else ifeq ($(PROCESSOR_ARCHITECTURE),aarch64)
	@echo "Apple Silicon machine detected."
	@echo "Please look at README.apple!"
else
	@echo "Good to go!"
endif
