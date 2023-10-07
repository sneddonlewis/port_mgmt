include(FetchContent)

#set(PostgreSQL_INCLUDE_DIR "/opt/homebrew/opt/libpq/include")
#set(PostgreSQL_LIBRARY "/opt/homebrew/opt/libpq/lib")
#find_package(PostgreSQL REQUIRED)

# Specify paths for libpq
set(PostgreSQL_INCLUDE_DIR "/opt/homebrew/opt/libpq/include")
set(PostgreSQL_LIBRARY "/opt/homebrew/opt/libpq/lib/libpq.dylib")  # Adjust to .a for static linking if desired

# Require PostgreSQL (libpq)
find_package(PostgreSQL REQUIRED)

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