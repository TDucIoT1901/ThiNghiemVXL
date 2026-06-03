#include <stdio.h>
#include <regx51.h>
int giatri=0;
// Tạo bảng mã LED tương ứng
unsigned char maled[10] = {
    0x3F, // 0
    0x06, // 1
    0x5B, // 2
    0x4F, // 3
    0x66, // 4
    0x6D, // 5
    0x7D, // 6
    0x07, // 7
    0x7F, // 8
    0x6F  // 9
};
// Định nghĩa các chân Trans 
sbit Trans1 = P1^0; //Led0 đơn vị 
sbit Trans2 = P1^1; //Led1 chục
sbit Trans3 = P1^2; //Led2 trăm (để luôn tắt)
sbit Trans4 = P1^3; //Led3 nghìn (để luôn tắt)
int Trans3 =0; // Luôn tắt LED trăm
int Trans4 =0; // Luôn tắt LED nghìn
// Tao hàm delay
void Delay(unsigned int time)
{
    unsigned int i, j;
    for(i=0; i<time; i++)
        for(j=0; j<1275; j++);
}
// Hàm main
int main()
{
    while(1)
    {   
        int chuc = giatri/10;
        int donvi = giatri%10;
        int solanquet=0;
        while (solanquet<50)
        {// Hiển thị số đơn vị
        P0 = maled[donvi];
        Trans1 = 1; 
        Delay(5); // Thời gian hiển thị cho LED
        Trans1 = 0; // Tắt LED đơn vị

        // Hiển thị số chục
        P0 = maled[chuc];
        Trans2 = 1;
        Delay(5); // Thời gian hiển thị cho LED
        Trans2 = 0; // Tắt LED chục

        // Tăng số lần quét
        solanquet++;
        }
        giatri++; // Tăng giá trị hiển thị
        if (giatri > 99) // Reset về 0 sau khi đạt 99
        giatri = 0;
    }
return 0;
}