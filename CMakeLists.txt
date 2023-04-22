cmake_minimum_required(VERSION 3.13)

project(smalltalkVM)

add_executable(smalltalkVM)
add_subdirectory(src)


add_subdirectory(templates/)
add_subdirectory(includes/)



###Debug
add_compile_options(-g -fkeep-inline-functions) #-fno-inline

### Testing
enable_testing()


get_target_property(SMALLTALKVM_SOURCES smalltalkVM SOURCES)
get_target_property(SMALLTALKVM_INCLUDES smalltalkVM INCLUDE_DIRECTORIES)

Function(addTest TESTNAME)
  add_executable(${TESTNAME} "${TESTNAME}.cpp")
  target_sources(${TESTNAME} PUBLIC ${SMALLTALKVM_SOURCES})
  target_include_directories(${TESTNAME} PUBLIC ${SMALLTALKVM_INCLUDES})
  
  add_test(NAME ${TESTNAME} COMMAND $<TARGET_FILE:${TESTNAME}>)
endFunction()

add_subdirectory(tests/)

target_sources(smalltalkVM PUBLIC "${PROJECT_SOURCE_DIR}/src/smalltalkVM.cpp")
