# Copyright (c) Open Enclave SDK contributors.
# Licensed under the MIT License.

set(EDL_FILE ../oe_gdb_test.edl)

add_custom_command(
  OUTPUT oe_gdb_test_t.h oe_gdb_test_t.c
  DEPENDS ${EDL_FILE} edger8r
  COMMAND
    edger8r --trusted ${EDL_FILE} --search-path ${PROJECT_SOURCE_DIR}/include
    ${DEFINE_OE_SGX} --search-path ${CMAKE_CURRENT_SOURCE_DIR})

add_enclave(
  TARGET
  oe_gdb_test_enc
  UUID
  ff375399-0b06-4189-9ddc-df5e38612e6d
  # The test would fail with the OpenSSL-based crypto wrapper
  # because the invocations of cpuid is not handled properly
  # (i.e., the SIGILL signal).
  CRYPTO_LIB
  mbedtls
  SOURCES
  enc.c
  contract.c
  ${CMAKE_CURRENT_BINARY_DIR}/oe_gdb_test_t.c)

enclave_include_directories(oe_gdb_test_enc PRIVATE ${CMAKE_CURRENT_BINARY_DIR})
enclave_link_libraries(oe_gdb_test_enc oelibc)
