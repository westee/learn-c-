#include <iostream>
#include <boost/json.hpp>   
#include <boost/filesystem.hpp>
#include <boost/filesystem/fstream.hpp>

namespace json = boost::json;
namespace fs = boost::filesystem;
using namespace std;

json::value
parse_file(char const *filename = "example.txt") {

   boost::filesystem::path currentPath = boost::filesystem::current_path();
   fs::path filePath = currentPath.append(filename);

   if (fs::exists(filePath) && fs::is_regular_file(filePath)) {
       fs::ifstream fileStream(filePath);
       if (fileStream.is_open()) {
           string content((istreambuf_iterator<char>(fileStream)), istreambuf_iterator<char>());
           fileStream.close();
           return json::parse(content);
       } else {
           cerr << "Unable to open file: " << filePath << endl;
       }
   } else {
       cerr << "File does not exist or is not a regular file: " << filePath << endl;
   }
   return "";
}

int main(int argc, char *argv[]) {
    json::object obj;
    obj["name"] = "张三";
    obj["age"] = 18;
    auto &skills = obj["skills"].emplace_array();
    skills.push_back("java");
    skills.push_back("c++");

    json::array arr( { "Hello", 42, true } );
    obj["dif"] = arr;

    json::object robj( {{"key1", "value1" }, { "key2", 42 }, { "key3", false }} );
    obj["obj"] = robj;

    cout << obj << endl;

   json::value jv = argc > 1 ? parse_file( argv[1]) :  parse_file();
   cout << jv << endl;
   cout << jv.as_object()["name"] << endl;
    return 0;
}
