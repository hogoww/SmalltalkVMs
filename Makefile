#Compilation stuff
CC=g++
PROJECT_OPTIONS=-std=c++14 -Wall
MAIN_NAME=main

OBJECTS=$(OBJECTS_DIR)*.o

#projects directories paths
SOURCES_DIR=src/
OBJECTS_DIR=obj/
TEST_DIR=tests/

default_target: project #generaly more usefull in the developpement process
.PHONY : default_target

#############################################
#Build the external files to be linked later#
#############################################
sourcesCompilation:
	cd $(SOURCES_DIR) &&\
	 $(CC) *.cpp $(PROJECT_OPTIONS) -c  &&\
	 mv *.o ../$(OBJECTS_DIR)
.PHONY : sourcesCompilation

#############################
#Build only the project part#
#############################
project:
	@echo "---------------------"
	@echo "|Generating Project |"
	@echo "---------------------"
	@make sourcesCompilation
	@make linking
	@echo ""
	@echo "Compilation of the project finished!"
.PHONY : project

linking:
	$(CC) $(OBJECTS) $(PROJECT_OPTIONS) -o $(MAIN_NAME)
	@echo ""
	@echo "Linking of the project finished!"
.PHONY:linking

###################################################################
#Clean working directory and redo every compilation unit necessary#
###################################################################

#"clean compilation"
cc:
	@make clean
	@make all
.PHONY : cc

##############################################################
#Clean the working directories of objects and temporary files#
##############################################################

#"clean working directories"
clean:
	@echo "----------------------"
	@echo "|Cleaning directories|"
	@echo "----------------------"	
	@cd $(OBJECTS_DIR) && rm -rf *.o || true
	@cd $(SOURCES_DIR) && rm -f *~ \#* || true
	@rm -f *~ \#* || true
.PHONY : clean

