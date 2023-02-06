#Compilation stuff
CC=g++
CPPFLAGS=-std=c++14 -Wall -I$(HEADERS_DIR)

MAKEFILE_PATH=$(dir $(abspath $(lastword $(MAKEFILE_LIST))))

#projects directories paths
SOURCES_DIR=$(MAKEFILE_PATH)src/
HEADERS_DIR=$(MAKEFILE_PATH)includes/
OBJECTS_DIR=$(MAKEFILE_PATH)obj/
TESTS_DIR=$(MAKEFILE_PATH)tests/
EXECUTABLES_DIR=$(MAKEFILE_PATH)executables/

SOURCES=$(wildcard $(SOURCES_DIR)*.cpp)
OBJECTS=$(addprefix $(OBJECTS_DIR),$(addsuffix .o ,$(basename $(notdir $(SOURCES)))))
TESTS=$(addprefix $(EXECUTABLES_DIR), $(basename $(notdir $(wildcard $(TESTS_DIR)*.cpp))))

CLEAN_FLAGS=*.o *~ \#*

default_target: project #generaly more usefull in the developpement process
.PHONY : default_target


$(OBJECT_DIR)%.o:
	@echo "----------------------------------------------"
	@echo "| Compiling $@ |"
	@echo "----------------------------------------------"
	$(CC) $(CPPFLAGS) $(addprefix $(SOURCES_DIR), $(notdir $(addsuffix .cpp, $(basename $@)))) -c
	mv *.o $(OBJECTS_DIR)

main: $(OBJECTS)
	@echo "-------------------------------"
	@echo "| Compiling $@ |"
	@echo "-------------------------------"
	$(CC) $(CPPFLAGS) $(OBJECTS) $@.cpp -o $@
	mv $@ $(EXECUTABLES_DIR)

$(TESTS): $(OBJECTS)
	@echo "-------------------------------"
	@echo "| Compiling $@ |"
	@echo "-------------------------------"
	$(CC) $(CPPFLAGS) $(OBJECTS) $(addprefix $(TESTS_DIR), $(notdir $@.cpp)) -o $@
	mv $@ $(EXECUTABLES_DIR)

#############################
#Build only the project part#
#############################
project:
	@echo "----------------------"
	@echo "| Generating Project |"
	@echo "----------------------"
	make main
	@echo ""
	@echo "Main Compilation finished!"
.PHONY : project


tests:
	@echo "-------------------------"
	@echo "| Generating Test cases |"
	@echo "-------------------------"
	make $(TESTS)
	@echo ""
	@echo "Compilation of the project finished!"
.PHONY : tests


###################################################################
#Clean working directory and redo every compilation unit necessary#
###################################################################

#"clean compilation"
cc:
	@make clean
	@make project
.PHONY : cc

##############################################################
#Clean the working directories of objects and temporary files#
##############################################################

#"clean working directories"
clean:
	@echo "------------------------"
	@echo "| Cleaning directories |"
	@echo "------------------------"	
	cd $(OBJECTS_DIR) && $(RM) $(CLEAN_FLAGS) || true
	cd $(SOURCES_DIR) && $(RM) $(CLEAN_FLAGS) || true
	cd $(HEADERS_DIR) && $(RM) $(CLEAN_FLAGS) || true
	cd $(TESTS_DIR) && $(RM) $(CLEAN_FLAGS) || true
	$(RM) $(CLEAN_FLAGS) || true
.PHONY : clean
