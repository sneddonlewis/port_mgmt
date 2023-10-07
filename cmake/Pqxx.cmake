include(FetchContent)

if(APPLE)
    # Set the paths explicitly for MacOS
    set(PostgreSQL_INCLUDE_DIR "/opt/homebrew/opt/libpq/include")
    set(PostgreSQL_LIBRARY "/opt/homebrew/opt/libpq/lib/libpq.dylib")
elseif(UNIX AND NOT APPLE)  # Linux
    # Allow the system to find it or set a probable path
    find_package(PostgreSQL REQUIRED)

    if(NOT PostgreSQL_FOUND)
        # Set probable paths for Ubuntu/RedHat
        find_path(PostgreSQL_INCLUDE_DIR NAMES libpq-fe.h PATHS "/usr/include/postgresql" "/usr/pgsql-9.3/include/")
        find_library(PostgreSQL_LIBRARY NAMES pq PATHS "/usr/lib" "/usr/pgsql-9.3/lib/")
    endif()
endif()

# Validate the paths
if(NOT EXISTS ${PostgreSQL_INCLUDE_DIR} OR NOT EXISTS ${PostgreSQL_LIBRARY})
    message(FATAL_ERROR "Cannot find PostgreSQL. Check your installation or specify paths manually.")
endif()

FetchContent_Declare(
        libpqxx
        GIT_REPOSITORY https://github.com/jtv/libpqxx.git
        GIT_TAG 7.8.1
)

FetchContent_MakeAvailable(libpqxx)

# If the PostgreSQL::PostgreSQL target is not defined, define it manually
if(NOT TARGET PostgreSQL::PostgreSQL)
    add_library(PostgreSQL::PostgreSQL UNKNOWN IMPORTED)
    set_target_properties(PostgreSQL::PostgreSQL PROPERTIES
            IMPORTED_LOCATION "${PostgreSQL_LIBRARY}"
            INTERFACE_INCLUDE_DIRECTORIES "${PostgreSQL_INCLUDE_DIR}"
    )
endif()