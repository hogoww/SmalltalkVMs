cmake_minimum_required(VERSION 3.13)

project(smalltalkVM)

add_executable(smalltalkVM)
add_subdirectory(src)


target_include_directories(smalltalkVM PUBLIC
				       "${PROJECT_SOURCE_DIR}/includes/"
				       "${PROJECT_SOURCE_DIR}/templates")



###Debug
add_compile_options("-g")

### Testing
enable_testing()

get_target_property(SMALLTALKVM_SOURCES smalltalkVM SOURCES)
Function(addTest TESTNAME)
  add_executable(${TESTNAME} "${TESTNAME}.cpp")
  target_sources(${TESTNAME} PUBLIC ${SMALLTALKVM_SOURCES})
  target_include_directories(${TESTNAME} PUBLIC
  					 "${PROJECT_SOURCE_DIR}/includes/"
					 "${PROJECT_SOURCE_DIR}/templates")
  
  add_test(NAME ${TESTNAME} COMMAND $<TARGET_FILE:${TESTNAME}>)
endFunction()

add_subdirectory(tests/)

target_sources(smalltalkVM PUBLIC "${PROJECT_SOURCE_DIR}/src/smalltalkVM.cpp")
