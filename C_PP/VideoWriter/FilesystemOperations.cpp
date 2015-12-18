#define BOOST_SYSTEM_NO_DEPRECATED

#include "boost/filesystem.hpp"

namespace filesystem_operations {

    void createFolderIfNotExist(const std::string& folder) {
        if (!boost::filesystem::exists(folder.c_str())) {
            boost::filesystem::create_directory(folder.c_str());
        }
    }
}
