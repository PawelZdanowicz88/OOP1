#include <string>
#include <iostream>
#include <fstream>
class address
{
public:
    std::string city;
    std::string street;
    int num_house;
    int num_flat;
    address()
    {
        city = "Неуказан";
        street = "Неуказан";
        num_house = 0;
        num_flat = 0;
    }
    std::string get_output_address() {
        std::string s = std::to_string(num_house);
        std::string s1 = std::to_string(num_flat);
        std::string output_address = city + ", " + street + ", " + s + ", " + s1;
        return output_address;
    }

};
int main()
{
    int sum_blocks = 0;
    std::ifstream fin("in.txt");
    fin >> sum_blocks;
    std::ofstream entry("out.txt");
    entry << sum_blocks << std::endl;
    address* arr = new address[sum_blocks];
    for (int i = 0; i < sum_blocks; ++i) {
        fin >> arr[i].city;
        fin >> arr[i].street;
        fin >> arr[i].num_house;
        fin >> arr[i].num_flat;
    }
    for (int i = (sum_blocks - 1); i >= 0; --i) {
        entry << arr[i].get_output_address() << std::endl;
    }
    fin.close();
    entry.close();
    delete[] arr;
    return 0;
}
