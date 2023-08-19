#include <cstdio>
#include <cmath>
#include <string>

using namespace std;

int main() {
    int a,b;
    scanf("%d%d",&a,&b);

    int result = a + b;
    int temp = abs(result);
    string output = "";
    int count = 0;

    while(temp != 0) {
        int a = temp % 10;
        output += temp % 10 + '0';
        temp /= 10;

        count = (count + 1) % 3;

        if(temp != 0 && count == 0) {
            output = output + ','; 
        }
    }

    reverse(output.begin(), output.end());
    
    if(result < 0){
        output = '-' + output;
    }

    if(result == 0) {
        output = '0';
    }

    printf("%s\n", output.c_str());
    return 0;
}