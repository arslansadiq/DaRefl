// ************************************************************************** //
//
//  Reflectometry simulation software prototype
//
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @authors   see AUTHORS
//
// ************************************************************************** //

#include "test_utils.h"
#include "testconfig.h" // this file is auto generated by the build system in build directory
#include <QFile>
#include <QString>
#include <QTextStream>
#include <mvvm/utils/fileutils.h>
#include <stdexcept>
#include <string>

using namespace ModelView;

namespace
{
void SaveDocument(const QJsonDocument& document, const std::string& fileName);
}

std::string TestUtils::TestOutputDir()
{
    return TestConfig::TestOutputDir(); // defined in auto-generated testconfig.h
}

std::string TestUtils::CreateTestDirectory(const std::string& test_sub_dir)
{
    std::string result = TestDirectoryPath(test_sub_dir);
    Utils::create_directory(result);
    return result;
}

std::string TestUtils::TestDirectoryPath(const std::string& test_sub_dir)
{
    return TestOutputDir() + std::string("/") + test_sub_dir;
}

std::string TestUtils::TestFileName(const std::string& test_sub_dir, const std::string& file_name)
{

    return TestDirectoryPath(test_sub_dir) + std::string("/") + file_name;
}

std::string TestUtils::CreateTestFile(const std::string& dirname, const std::string& fileName)
{
    std::string filename = dirname.empty() ? fileName : dirname + "/" + fileName;

    QFile file(QString::fromStdString(filename));
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
        throw std::runtime_error("TestFileUtils::createTestFile() -> Error. "
                                 "Can't create file");

    QTextStream out(&file);
    out << "Test file " << 42 << "\n";
    file.close();

    return filename;
}

std::string TestUtils::CreateEmptyFile(const std::string& dirname, const std::string& fileName)
{
    std::string filename = dirname.empty() ? fileName : dirname + "/" + fileName;

    QFile file(QString::fromStdString(filename));
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
        throw std::runtime_error("TestFileUtils::createTestFile() -> Error. "
                                 "Can't create file");
    return filename;
}
