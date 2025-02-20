# Create a library called "lwm2m_client_zynq"
add_library(lwm2m_client_zynq_lib lwm2m_client_zynq.cpp)
add_library(lwm2m_server_zynq_lib lwm2m_server_zynq.cpp)

# Specify include directories for the library
target_include_directories(lwm2m_client_zynq_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../../include)
# Specify include directories for the library
target_include_directories(lwm2m_server_zynq_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../../include)
