default: release

.PHONY: default release debug all clean

include make-utils/flags.mk
include make-utils/cpp-utils.mk

CXX_FLAGS += -Iinclude -ICatch/include -Werror

ifneq (,$(findstring clang,$(CXX)))
CXX_FLAGS += -stdlib=libc++
endif

LD_FLAGS += -pthreads

CPP_FILES=$(wildcard test/*.cpp)
TEST_FILES=$(CPP_FILES:test/%=%)

DEBUG_D_FILES=$(CPP_FILES:%.cpp=debug/%.cpp.d)
RELEASE_D_FILES=$(CPP_FILES:%.cpp=release/%.cpp.d)

$(eval $(call folder_compile,workbench))
$(eval $(call test_folder_compile,))

# Create executables
$(eval $(call add_test_executable,test,$(TEST_FILES)))
$(eval $(call add_executable_set,test,test))

release: release_test
release_debug: release_debug_test
debug: debug_test

all: release release_debug debug

debug_test: debug
	./debug/bin/test

release_test: release
	./release/bin/test

release_debug_test: release_debug
	./release_debug/bin/test

cpp_test: debug/bin/test release_debug/bin/test release/bin/test
	./debug/bin/test
	./release_debug/bin/test
	./release/bin/test

clean: base_clean

-include $(DEBUG_D_FILES)
-include $(RELEASE_D_FILES)
