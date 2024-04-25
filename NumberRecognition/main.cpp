// this file is the driver class for the number recogniton machine learing ai
// Michael Rizig
// 3/1/24

#include <iostream>
#include "Learning.h"
#include <fstream>
#include "image.h"
using namespace std;

void parseData(std::vector<image> &images)
{
    std::ifstream file("daNums.txt");
    std::string line;
    int value;
    while (std::getline(file, line))
    {
        // inserting value from label into datapoint
        value = std::stoi(line.substr(line.size() - 1, line.size()));
        image temp;
        temp.label = value;
        // inserting imageBools into bool array
        line.erase(line.end() - 2, line.end());
        for (int i = 0; i < 28; i++)
        {
            for (int j = 0; j < 28; j++)
            {
                if (line[0] == 'F')
                {
                    temp.imageBools[i][j] = false;
                    line = line.substr(5);
                }
                else if (line[0] == 'T')
                {
                    temp.imageBools[i][j] = true;
                    line = line.substr(4);
                }
            }
        }
        images.insert(images.begin(), temp);
    }
}
int main()
{
    learning s;
    std::vector<image> images;
    parseData(images);
    for (int i = 0; i < 28; i++)
    {
        for (int j = 0; j < 28; j++)
        {
            cout << images.at(488).imageBools[i][j];
        }
        cout << endl;
    }

    cout << images.at(488).label << endl;
    cout << 100 * s.calculateAccuracy(images) << "%" << endl;
    std::cout << "\nHello, World!" << std::endl;
    int data;
    std::cin >> data;
    return 0;
}
