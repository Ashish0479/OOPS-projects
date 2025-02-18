#include <iostream>
using namespace std;
class add
{
    int arr[10];
    int target;
    int n;

public:
    void get_data()
    {
        cout << "enter number of elements:";
        cin >> n;
        cout << "enter array elements :";
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        cout << "enter target:";
        cin >> target;
    };
    void index()
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (arr[i] + arr[j] == target)
                {
                    cout << i << "," << j << endl;
                }
            }
        }
    };
};
int main()
{
    add a1;
    a1.get_data();
    a1.index();
    return 0;
}