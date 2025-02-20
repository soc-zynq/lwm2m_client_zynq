PROJECT(lwm2m_server_zynq)


# Add source files
add_executable(lwm2m_server_zynq main.cpp)

# Link the project library
target_link_libraries(lwm2m_server_zynq
    PRIVATE
    lwm2m_server_lib
    ${WAKAAMA_LIBRARIES}
    pthread
)
