#include <iostream>
using namespace std;
bool find(int arr[], int x, int y, int i, bool qx, bool qy)
{
    if(i == 3)
        return (qx && qy);
    qx = qx || (x == arr[i]);
    qy = qy || (y == arr[i]) || (y == 0);
    return ((qx && qy) || find(arr, x, y, i+1, qx, qy));

}

int cut(int L, int arr[], int i, int max)
{
    if(i == 3)
    {
        if(max == 0)
            return -1;
        else
            return max;
    }
    int pieces = L/arr[i] + int(bool(L%arr[i]));
    if(find(arr, (L/arr[i])*arr[i], L%arr[i], 0, false, false) &&  pieces > max){
        max = pieces;
    }
    return cut(L, arr, i+1, max);
}
int main() {
    int L = 25;
    int arr[] = { 11, 12, 13};
    cout<<cut(L, arr, 0, 0);
	return 0;
}