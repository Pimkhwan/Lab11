#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <cmath>
#include <iomanip>
using namespace std;

int main()
{
    int NumOfdata = 0;
    double sum = 0;
    string textline;
    ifstream source;
    source.open("score.txt");
    while (getline(source,textline))
    {
        sum += atof(textline.c_str());
        NumOfdata++;
    }
    cout << "Number of data = " << NumOfdata << endl << setprecision(3);
    cout << "Mean = " << sum/NumOfdata << endl;
    source.close();
    source.open("score.txt");
    double mean = sum/NumOfdata;
    sum = 0;
    NumOfdata = 0;
    while (getline(source,textline))
    {
        sum += ((atof(textline.c_str())-mean)*(atof(textline.c_str())-mean));
        NumOfdata++;
    }
    double deviation = sqrt(sum/NumOfdata);
    cout << "Standard deviation = " << deviation ;
    source.close();
    return 0;
}