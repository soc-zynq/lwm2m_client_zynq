PROJECT(lwm2m_client_zynq)

# Add source files
add_executable(${PROJECT_NAME} main.cpp)

# Link the project library
target_link_libraries(${PROJECT_NAME} lwm2m_client_zynq_lib)
