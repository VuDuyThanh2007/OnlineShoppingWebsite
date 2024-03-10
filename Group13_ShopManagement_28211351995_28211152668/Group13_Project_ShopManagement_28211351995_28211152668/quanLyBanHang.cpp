#include <iostream>
#include <iomanip>
#include <windows.h>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <limits>

using namespace std;

void mainMenu()
{
    //Hien thi phan menu chinh cua phan mem
    cout << "********************************************\n";
    cout << "**  1.  " << "Nhap thong tin hang hoa           **\n";
    cout << "**  2.  " << "Nhap thong tin khach hang         **\n";
    cout << "**  3.  " << "Hien thi thong tin hang hoa       **\n";
    cout << "**  4.  " << "Hien thi thong tin khach hang     **\n";
    cout << "**  5.  " << "Cap nhat thong tin hang hoa       **\n";
    cout << "**  6.  " << "Cap nhat thong tin khach hang     **\n";
    cout << "**  7.  " << "Them thong tin hang hoa           **\n";
    cout << "**  8.  " << "Them thong tin khach hang         **\n";
    cout << "**  9.  " << "Xoa thong tin hang hoa            **\n";
    cout << "**  10. " << "Xoa thong tin khach hang          **\n";
    cout << "**  11. " << "Tim thong tin hang hoa            **\n";
    cout << "**  12. " << "Tim thong tin khach hang          **\n";
    cout << "**  13. " << "Sap xep thong tin hang hoa        **\n";
    cout << "**  14. " << "Sap xep thong tin khach hang      **\n";
    cout << "**  0.  " << "Thoat khoi ung dung               **\n";
    cout << "********************************************\n";
}
void returnMainMenu()
{
    //tao ra mot bien co kieu du lieu la char sau khi nhap 1 ky tu bat ky tu ban phim thi xoa man hinh va hien thi menu chinh
    char ch;
    cout << "Nhap ky tu bat ky de tro ve man hinh chinh: ";
    cin >> ch;
    system("cls");
    mainMenu();
}
void findHHMenu()
{
    //menu cua chuc nang tim kiem thong tin hang hoa
    cout << "(1) Tim kiem theo ma hang hoa\n";
    cout << "(2) Tim kiem theo ten hang hoa\n";
    cout << "(0) Thoat khoi che do tim kiem hang hoa\n";
}
void returnfindHHMenu()
{
    //tao ra mot bien co kieu du lieu la char sau khi nhap 1 ky tu bat ky tu ban phim thi xoa man hinh va hien thi menu tim kiem thong tin hang hoa
    char ch;
    cout << "Nhap ky tu bat ky de quay lai: ";
    cin >> ch;
    system("cls");
    findHHMenu();
}
void findKHMenu()
{
    //menu tim kiem thong tin khach hang
    cout << "(1) Tim kiem theo ma khach hang\n";
    cout << "(2) Tim kiem theo ten khach hang\n";
    cout << "(0) Thoat khoi che do tim kiem khach hang\n";
}
void returnfindKHMenu()
{
    //tao ra mot bien co kieu du lieu la char sau khi nhap 1 ky tu bat ky tu ban phim thi xoa man hinh va hien thi menu tim kiem khach hang
    char ch;
    cout << "Nhap ky tu bat ky de quay lai: ";
    cin >> ch;
    system("cls");
    findKHMenu();
}
void sapXepHHMenu()
{
    //menu sap xep thong tin hang hoa
    cout << "(1) Sap xep theo ten hang hoa\n";
    cout << "(2) Sap xep theo so luong hang hoa con lai\n";
    cout << "(3) Sap xep theo gia hang hoa\n";
    cout << "(4) Sap xep theo ngay nhap hang\n";
    cout << "(5) Sap xep theo han su dung\n";
    cout << "(0) Thoat khoi che do sap xep hang hoa\n";
}
void returnsapXepHHMenu()
{
    //tao ra mot bien co kieu du lieu la char sau khi nhap 1 ky tu bat ky tu ban phim thi xoa man hinh va hien thi menu sap xep thong tin hang hoa
    char ch;
    cout << "Nhap ky tu bat ky de quay lai: ";
    cin >> ch;
    system("cls");
    sapXepHHMenu();
}
void sapXepKHMenu()
{
    //menu sap xep thong tin khach hang
    cout << "(1) Sap xep theo ten khach hang\n";
    cout << "(2) Sap xep theo diem tich luy cua khach hang\n";
    cout << "(0) Thoat khoi che do sap xep khach hang\n";
}
void returnsapXepKHMenu()
{
    //tao ra mot bien co kieu du lieu la char sau khi nhap 1 ky tu bat ky tu ban phim thi xoa man hinh va hien thi menu sap xep thong tin khach hang
    char ch;
    cout << "Nhap ky tu bat ky de quay lai: ";
    cin >> ch;
    system("cls");
    sapXepKHMenu();
}
bool kiemTraKyTu (string s)
{
    //kiem tra xem trong chuoi co chua ky tu so hay khong
    for (int i=0; i<s.length(); i++)
    {
        if (s[i]==' ')
        {
            continue;
        }
        if ((s[i]<'a' || s[i]>'z') && (s[i] <'A' || s[i] > 'Z')) //neu khong thuoc cac ky tu chu thi tra ve false
        {
            return false;
        }
    }
    return true;
}
bool kiemTraMa(string s)
{
    for (int i=0; i<s.length(); i++)
    {
        if ((s[i]<'a' || s[i]>'z') && (s[i] <'A' || s[i] > 'Z') &&(s[i] <'0' || s[i] > '9') )
        {
            return false;
        }
    }
    return true;
}
bool kiemTraMaTrung(string *tam,string s,int size)
{
    for (int i=0; i<size; i++)
    {
        if (tam[i]==s)
        {
            return false;
        }
    }
    return true;
}
bool kiemTraSDT(string s)
{
    //Ham dung de kiem tra so dien thoai
    int n=s.length();
    for (int i=0; i<s.length(); i++)
    {
        if (s[i]<'0'||s[i]>'9') //so dien thoai chi duoc chua cac ky tu la so
        {
            return false;
        }
        if (n!=10) //so dien thoai chi chua 10 so
        {
            return false;
        }
    }
    return true;
}
bool kiemTraSo(string s)
{
    //ham dung de kiem tra cac ky tu nhap vao chi bao gom so (dung trong viec nhap cac lua chon tu ban phim)
    int n=s.length();
    for (int i=0; i<s.length(); i++)
    {
        if (s[i]<'0'||s[i]>'9')
        {
            return false;
        }
    }
    return true;
}
string format(string name)
{
    //chinh lai phong chu cho phu hop cac chu cai dau viet hoa va giua cac chu chi co 1 dau cach
    int n=name.length();
    //Xoa dau cach
    for(int i=0; i<n; i++)
    {
        if(name[0]==' ')
        {
            for (int k=0; k<n; k++)
            {
                name[k] = name[k+1];
            }
            n--;
            i--;
        }
        if(name[i]==' '&&name[i+1]==' ')
        {
            for (int k=i; k<n; k++)
            {
                name[k] = name[k+1];
            }
            n--;
            i--;
        }
    }
    name[n] = '\0';
    //Viet hoa cac chu cai dau
    for (int i=0; i<n; i++)
    {
        if(name[0]>='a'&&name[0]<='z')
        {
            name[0]-=32;
        }
        if (name[i-1]==' ' && name[i]>='a' && name[i]<='z')
        {
            name[i]-=32;
        }
        if (name[i-1]!=' ' && name[i]>='A' && name[i]<='Z')
        {
            name[i]+=32;
        }
    }
    return name;
}
int nhapSo()
{
    //Ham de nhap cac lua chon tu ban phim sao cho phu hop voi chuong trinh
    string temp;
    do
    {
        do
        {
            getline(cin, temp);
        }
        while (temp.length()==0);
        if (kiemTraSo(temp)==false)
        {

            cout << "Khong hop le vui long nhap lai: ";
        }
    }
    while(kiemTraSo(temp)==false);
    int n = stoll(temp);
    return n;
}
class Date
{
public:
    int ngay, thang, nam;
    bool setDate (int ngay, int thang, int nam)
    {
        if (nam<0)
        {
            return false;
        }
        else
        {
            if (thang<1 || thang>12)
            {
                return false;
            }
            else
            {
                if (thang==1 || thang==3 || thang==5 || thang==7 || thang==8 || thang==10 || thang==12)
                {
                    if (ngay<1 || ngay>31)
                    {
                        return false;
                    }
                }
                else if (thang==4 || thang==6 || thang==9 || thang==11)
                {
                    if (ngay<1 || ngay>30)
                    {
                        return false;
                    }
                }
                else if (thang==2)
                {
                    if(nam%4==0 && (nam%400==0 || nam%100!=0))
                    {
                        if (ngay<1 || ngay>29)
                        {
                            return false;
                        }
                    }
                    else
                    {
                        if (ngay<1 || ngay>28)
                        {
                            return false;
                        }
                    }
                }
            }
        }
        return true;
    }

    void input()
    {
        do
        {
            cin >> this->ngay >> this->thang >> this->nam;
            if (setDate(this->ngay, this->thang, this->nam) == false || cin.fail())
            {
                cout << "Khong hop le vui long nhap lai: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        }
        while (setDate(this->ngay, this->thang, this->nam) == false || cin.fail());
    }

    void display()
    {
        cout << this->ngay << "-" << this->thang << "-" << this->nam;
    }

    int getTongNgay()
    {
        int soNgayTam=0;
        for(int i=0; i<this->nam; i++)
        {
            if (i%4==0&&(i%400==0||i%100!=0))
            {
                soNgayTam+=366;
            }
            else
            {
                soNgayTam+=365;
            }
        }
        for (int i=1; i<this->thang; i++)
        {
            if (i==1||i==3||i==5||i==7||i==8||i==10||i==12)
            {
                soNgayTam+=31;
            }
            else if (i==2)
            {
                if (nam%4==0&&(nam%400==0||nam%100!=0))
                {
                    soNgayTam+=29;
                }
                else
                {
                    soNgayTam+=28;
                }
            }
            else if (i==4||i==6||i==9||i==11)
            {
                soNgayTam+=30;
            }
        }
        soNgayTam+=this->ngay;
        return soNgayTam;
    }

    int getDoDai()
    {
        string namT = to_string(this->nam);
        string thangT = to_string(this->thang);
        string ngayT = to_string(this->ngay);
        int n = namT.length() + thangT.length() + ngayT.length();
        return n+2;
    }
};
class ThongTin
{
public:
    virtual void layDuLieu() {};
    virtual void luuThongTin() {};
    virtual void nhapThongTin() {};
    virtual void hienThiThongTin() {};
    virtual void input() {};
    virtual void display() {};
    virtual void capNhapThongTin() {};
    virtual void themThongTin() {};
    virtual void xoaThongTin() {};
    virtual void timKiemThongTin() {};
    virtual void sapXepThongTin() {};
};
//Lop hang hoa
class HangHoa : public ThongTin
{
private:
    string maHH;
    string tenHangHoa;
    long gia;
    int soLuong;
    string donVi;
    Date ngayNhap;
    Date hanSuDung;
    HangHoa* listHH;
    int size=0;
public:
    friend class Date;
    HangHoa();
    HangHoa (const HangHoa &other);
    void layDuLieu();
    void luuThongTin();
    void nhapThongTin();
    void hienThiThongTin();
    void input();
    void display();
    void capNhapThongTin();
    void themThongTin();
    void xoaThongTin();
    void timKiemThongTin();
    void sapXepThongTin();
};
//Cac ham o ben ngoai lop
HangHoa::HangHoa()
{
    listHH == nullptr;
    size = 0;
}
HangHoa::HangHoa (const HangHoa &other)
{
    this->maHH = other.maHH;
    this->tenHangHoa = other.tenHangHoa;
    this->gia = other.gia;
    this->soLuong = other.soLuong;
    this->donVi = other.donVi;
    this->ngayNhap = other.ngayNhap;
    this->hanSuDung = other.hanSuDung;
}
void HangHoa::layDuLieu()
{
    ifstream fi ("HangHoa.txt");
    fi >> this->size;
    listHH = new HangHoa[this->size];
    for (int i=0; i<this->size; i++)
    {
        do
        {
            getline(fi, listHH[i].maHH);
        }
        while (listHH[i].maHH.length()==0);
        do
        {
            getline(fi, listHH[i].tenHangHoa);
        }
        while (listHH[i].tenHangHoa.length()==0);
        do
        {
            getline(fi, listHH[i].donVi);
        }
        while (listHH[i].donVi.length()==0);
        fi >> listHH[i].gia;
        fi >> listHH[i].soLuong;
        fi >> listHH[i].ngayNhap.ngay;
        fi >> listHH[i].ngayNhap.thang;
        fi >> listHH[i].ngayNhap.nam;
        fi >> listHH[i].hanSuDung.ngay;
        fi >> listHH[i].hanSuDung.thang;
        fi >> listHH[i].hanSuDung.nam;
    }
    fi.close();
}
void HangHoa::luuThongTin()
{
    ofstream fo ("HangHoa.txt");
    fo << this->size << endl;
    for (int i=0; i<this->size; i++)
    {
        fo << listHH[i].maHH << endl;
        fo << format(listHH[i].tenHangHoa) << endl;
        fo << format(listHH[i].donVi) << endl;
        fo << listHH[i].gia << endl;
        fo << listHH[i].soLuong << endl;
        fo << listHH[i].ngayNhap.ngay << " ";
        fo << listHH[i].ngayNhap.thang << " ";
        fo << listHH[i].ngayNhap.nam << endl;
        fo << listHH[i].hanSuDung.ngay << " ";
        fo << listHH[i].hanSuDung.thang << " ";
        fo << listHH[i].hanSuDung.nam << endl;
    }
    fo.close();
}
void HangHoa::nhapThongTin()
{
    layDuLieu();
    cout << "Ma hang hoa: ";
    string *tam=new string[this->size];
    for (int i=0; i<size; i++)
    {
        tam[i]=listHH[i].maHH;
    }
    do
    {
        do
        {
            getline(cin, maHH);
        }
        while (maHH.length()==0);

        if (kiemTraMa(maHH)==false)
        {
            cout << "Khong hop le vui long nhap lai: ";
        }
        else if (kiemTraMaTrung(tam,maHH,size)==false)
        {
            cout << "Ma hang hoa da ton tai vui long nhap lai: ";
        }
    }
    while(kiemTraMa(maHH)==false||kiemTraMaTrung(tam,maHH,size)==false);

    cout << "Ten hang hoa: ";
    do
    {
        do
        {
            getline(cin, tenHangHoa);
        }
        while (tenHangHoa.length()==0);
        if (kiemTraKyTu(tenHangHoa)==false)
        {
            cout << "Khong hop le vui long nhap lai: ";
        }
        else if (tenHangHoa.length()>25)
        {
            cout << "Ten qua dai vui long nhap lai co the ghi tat: ";
        }
    }
    while (kiemTraKyTu(tenHangHoa)==false || tenHangHoa.length()>25);
    this->tenHangHoa = format(this->tenHangHoa);

    cout << "Don vi: ";
    do
    {
        do
        {
            getline(cin, donVi);
        }
        while (donVi.length()==0);
        if (kiemTraKyTu(donVi)==false)
        {
            cout << "Khong hop le vui long nhap lai: ";
        }
        else if (donVi.length()>11)
        {
            cout << "Don vi co van de vui long kiem tra va nhap lai: ";
        }
    }
    while (kiemTraKyTu(donVi)==false || donVi.length()>11);
    this->donVi = format(this->donVi);

    cout << "Gia san pham: ";
    gia = nhapSo();

    cout << "So luong san pham: ";
    soLuong = nhapSo();

    cout << "Ngay nhap hang (dd/mm/yyyy): ";
    ngayNhap.input();

    do
    {
        cout << "Han su dung(dd/mm/yyyy): ";
        hanSuDung.input();
    }
    while (hanSuDung.getTongNgay()<ngayNhap.getTongNgay());
}
void HangHoa::hienThiThongTin()
{
    cout << "Ma hang hoa: ";
    cout << this->maHH << endl;
    cout << "Ten hang hoa: ";
    cout << format(this->tenHangHoa) << endl;
    cout << "Don vi: ";
    cout << format(this->donVi) << endl;
    cout << "Gia san pham: ";
    cout << this->gia << endl;
    cout << "So luong san pham: ";
    cout << this->soLuong << endl;
    cout << "Ngay nhap hang: ";
    this->ngayNhap.display();
    cout << endl;
    cout << "Han su dung: ";
    this->hanSuDung.display();
    cout << endl;
}
void HangHoa::input()
{
    layDuLieu();
    cout << "Nhap so luong hang hoa muon nhap vao: ";
    int temp = nhapSo();
    HangHoa *hhtemp = new HangHoa [this->size+temp];
    string *tam=new string[this->size+temp];
    for (int i=0; i<this->size; i++)
    {
        hhtemp[i] = listHH[i];
        tam[i]=listHH[i].maHH;
    }
    for (int i=0; i<temp; i++)
    {
        cout << "San pham thu " << i+1 << endl;
        cout << "Ma hang hoa: ";
        do
        {
            bool check = true;
            do
            {
                getline(cin, hhtemp[this->size+i].maHH);
            }
            while (hhtemp[this->size+i].maHH.length()==0);

            if (kiemTraMa(hhtemp[this->size+i].maHH)==false)
            {
                cout << "Khong hop le vui long nhap lai: ";
            }
            else if (kiemTraMaTrung(tam,hhtemp[this->size+i].maHH,size+temp)==false)
            {
                cout << "Ma hang hoa da ton tai vui long nhap lai: ";
            }
        }
        while(kiemTraMa(hhtemp[this->size+i].maHH)==false||kiemTraMaTrung(tam,hhtemp[this->size+i].maHH,size+temp)==false);
        tam[this->size+i] = hhtemp[this->size+i].maHH;
        cout << "Ten hang hoa: ";
        do
        {
            do
            {
                getline(cin, hhtemp[this->size+i].tenHangHoa);
            }
            while (hhtemp[this->size+i].tenHangHoa.length()==0);
            if (kiemTraKyTu(hhtemp[this->size+i].tenHangHoa)==false)
            {
                cout << "Khong hop le vui long nhap lai: ";
            }
            else if (hhtemp[this->size+i].tenHangHoa.length()>25)
            {
                cout << "Ten qua dai vui long nhap lai co the ghi tat: ";
            }
        }
        while (kiemTraKyTu(hhtemp[this->size+i].tenHangHoa)==false || hhtemp[this->size+i].tenHangHoa.length()>25);
        hhtemp[this->size+i].tenHangHoa = format(hhtemp[this->size+i].tenHangHoa);

        cout << "Don vi: ";
        do
        {
            do
            {
                getline(cin, hhtemp[this->size+i].donVi);
            }
            while (hhtemp[this->size+i].donVi.length()==0);
            if (kiemTraKyTu(hhtemp[this->size+i].donVi)==false)
            {
                cout << "Khong hop le vui long nhap lai: ";
            }
            else if (hhtemp[this->size+i].donVi.length()>11)
            {
                cout << "Don vi co van de vui long kiem tra va nhap lai: ";
            }
        }
        while (kiemTraKyTu(hhtemp[this->size+i].donVi)==false || hhtemp[this->size+i].donVi.length()>11);
        hhtemp[this->size+i].donVi = format(hhtemp[this->size+i].donVi);

        cout << "Gia san pham: ";
        hhtemp[this->size+i].gia = nhapSo();

        cout << "So luong san pham: ";
        hhtemp[this->size+i].soLuong = nhapSo();

        cout << "Ngay nhap hang (dd/mm/yyyy): ";
        hhtemp[this->size+i].ngayNhap.input();

        do
        {
            cout << "Han su dung(dd/mm/yyyy): ";
            hhtemp[this->size+i].hanSuDung.input();
        }
        while (hhtemp[this->size+i].hanSuDung.getTongNgay()<hhtemp[this->size+i].ngayNhap.getTongNgay());
        cout << "____________________________________________" << endl;
    }
    delete [] listHH;
    listHH = hhtemp;
    this->size=this->size+temp;
    cout << "Nhap thanh cong!" << endl;
}
void HangHoa::display()
{
    layDuLieu();
    cout << "+-----+" << "--------------+" << "------------------------+" << "----------+" << "--------------+" << "----------+" << "----------------+" << "-------------+" << endl;
    cout << "| STT |" << "  Ma hang hoa |" << "      Ten hang hoa      |" << "  Don vi  |" << " Gia san pham |" << " So luong |" << " Ngay nhap hang |" << " Han su dung |" << endl;
    for (int i=0; i<this->size; i++)
    {
        cout << "+-----+" << "--------------+" << "------------------------+" << "----------+" << "--------------+" << "----------+" << "----------------+" << "-------------+" << endl;
        cout << "|" << i+1;
        string iT = to_string(i+1);
        cout.width(6-iT.length());
        cout << "|";
        cout << listHH[i].maHH;
        cout.width(15-listHH[i].maHH.length());
        cout << "|";
        cout << format(listHH[i].tenHangHoa);
        cout.width(25-listHH[i].tenHangHoa.length());
        cout << "|";
        cout << format(listHH[i].donVi);
        cout.width(11-listHH[i].donVi.length());
        cout << "|";
        cout << listHH[i].gia;
        string giaT = to_string(listHH[i].gia);
        cout.width(15-giaT.length());
        cout << "|";
        cout << listHH[i].soLuong;
        string soLuongT = to_string(listHH[i].soLuong);
        cout.width(11-soLuongT.length());
        cout << "|";
        listHH[i].ngayNhap.display();
        int ngayNhapT = listHH[i].ngayNhap.getDoDai();
        cout.width(17-ngayNhapT);
        cout << "|";
        listHH[i].hanSuDung.display();
        int hanSuDungT = listHH[i].hanSuDung.getDoDai();
        cout.width(14-hanSuDungT);
        cout << "|" << endl;
    }
    cout << "+-----+" << "--------------+" << "------------------------+" << "----------+" << "--------------+" << "----------+" << "----------------+" << "-------------+" << endl;
}
void HangHoa::capNhapThongTin()
{
    display();
    cout << "Nhap ma hoac ten hang hoa: ";
    string temp;
    do
    {
        getline(cin, temp);
    }
    while (temp.length()==0);
    int viTri=0;
    int demTam=0;
    for (int i=0; i<size; i++)
    {
        if ( temp==listHH[i].maHH || temp==listHH[i].tenHangHoa)
        {
            viTri = i;
            demTam++;
            break;
        }
    }
    if (demTam==0)
    {
        cout << "Ma hoac ten hang hoa khong ton tai!" << endl;
    }
    else
    {
        system("cls");
        listHH[viTri].hienThiThongTin();
        cout << "____________________________________________" << endl;
        cout << "(1) Ten hang hoa" << endl;
        cout << "(2) Don vi" << endl;
        cout << "(3) Gia" << endl;
        cout << "(4) So luong" << endl;
        cout << "(5) Ngay nhap hang" << endl;
        cout << "(6) Han su dung" << endl;
        cout << "____________________________________________" << endl;
        cout << "Lua chon thong tin muon cap nhap: ";
        int luaChon;
        do
        {
            do
            {
                luaChon = nhapSo();
                if (luaChon<1 || luaChon>6)
                {
                    cout << "Khong hop le vui long nhap lai: ";
                }
            }
            while (luaChon<1 || luaChon>6);
            if (luaChon==1)
            {
                cout << "Nhap ten hang hoa moi: ";
                do
                {
                    do
                    {
                        getline(cin, listHH[viTri].tenHangHoa);
                    }
                    while (listHH[viTri].tenHangHoa.length()==0);
                    if (kiemTraKyTu(listHH[viTri].tenHangHoa)==false)
                    {
                        cout << "Khong hop le vui long nhap lai: ";
                    }
                }
                while(kiemTraKyTu(listHH[viTri].tenHangHoa)==false);
                listHH[viTri].tenHangHoa = format(listHH[viTri].tenHangHoa);
                break;
            }
            else if (luaChon==2)
            {
                cout << "Nhap don vi moi: ";
                do
                {
                    do
                    {
                        getline(cin, listHH[viTri].donVi);
                    }
                    while (listHH[viTri].donVi.length()==0);
                    if (kiemTraKyTu(listHH[viTri].donVi)==false)
                    {
                        cout << "Khong hop le vui long nhap lai: ";
                    }
                }
                while (kiemTraKyTu(listHH[viTri].donVi)==false);
                listHH[viTri].donVi = format(listHH[viTri].donVi);
                break;
            }
            else if (luaChon==3)
            {
                cout << "Nhap gia moi: ";
                listHH[viTri].gia = nhapSo();
                break;
            }
            else if (luaChon==4)
            {
                cout << "Nhap so luong moi: ";
                listHH[viTri].soLuong = nhapSo();
                break;
            }
            else if (luaChon==5)
            {
                cout << "Nhap ngay nhap moi: ";
                do {
                    listHH[viTri].ngayNhap.input();
                } while (listHH[viTri].ngayNhap.getTongNgay()>listHH[viTri].hanSuDung.getTongNgay() && cout << "Khong hop le vui long nhap lai: ");
                break;
            }
            else if (luaChon==6)
            {
                cout << "Nhap han su dung moi: ";
                do {
                    listHH[viTri].hanSuDung.input();
                } while (listHH[viTri].ngayNhap.getTongNgay()>listHH[viTri].hanSuDung.getTongNgay() && cout << "Khong hop le vui long nhap lai: ");
                break;
            }
        }
        while (true);
        cout << "Cap nhap thong tin hang hoa thanh cong!" << endl;
    }
    luuThongTin();
}
void HangHoa::themThongTin()
{
    display();
    cout << "Nhap vi tri muon them hang hoa: ";
    int viTri;
    do
    {
        viTri=nhapSo();
        if (viTri<1||viTri>this->size)
        {
            cout << "Khong hop le vui long nhap lai: ";
        }
    }
    while ( viTri<1||viTri>this->size);
    viTri--;
    this->size=this->size+1;
    HangHoa *hhtempT = new HangHoa [this->size];
    hhtempT[viTri].nhapThongTin();
    for (int i=0; i<viTri; i++)
    {
        hhtempT[i] = listHH[i];
    }
    for (int i=viTri+1; i<this->size; i++)
    {
        hhtempT[i] = listHH[i-1];
    }
    delete [] listHH;
    listHH = hhtempT;
    luuThongTin();
    system("cls");
    cout << "DANH SACH HANG HOA SAU KHI THEM" << endl;
    cout << "____________________________________________" << endl;
    display();
    cout << "Them hang hoa thanh cong!" << endl;
}
void HangHoa::xoaThongTin()
{
    layDuLieu();
    display();
    cout << "Nhap vi tri muon xoa: ";
    int viTri;
    do
    {
        viTri=nhapSo();
        if (viTri<1||viTri>this->size)
        {
            cout << "Khong hop le vui long nhap lai: ";
        }
    }
    while ( viTri<1||viTri>this->size);
    viTri--;
    this->size--;
    HangHoa *listHHTemp = new HangHoa [this->size];
    for (int i=0; i<viTri; i++)
    {
        listHHTemp[i] = listHH[i];
    }
    for (int i=viTri; i<this->size; i++)
    {
        listHHTemp[i] = listHH[i+1];
    }
    delete [] listHH;
    listHH = listHHTemp;
    luuThongTin();
    system("cls");
    cout << "DANH SACH HANG HOA SAU KHI XOA\n";
    cout << "____________________________________________" << endl;
    display();
    cout << "Xoa hang hoa thanh cong!" << endl;
}
void HangHoa::timKiemThongTin()
{
    layDuLieu();
    cout << "Nhap lua chon: ";
    int timKiem;
    do
    {
        do
        {
            timKiem = nhapSo();
            if (timKiem<0 || timKiem>2)
            {
                cout << "Khong hop le vui long nhap lai: ";
            }
        }
        while (timKiem<0 || timKiem>2);
        if (timKiem==1)
        {
            system("cls");
            cout << "CHE DO TIM KIEM THEO MA HANG HOA\n";
            cout << "____________________________________________" << endl;
            string maTam; //nhap ma hang hoa muon tim kiem
            cout << "Nhap ma hang hoa muon tim kiem: ";
            do
            {
                getline(cin,maTam);
            }
            while (maTam.length()==0);
            int demTam=0;// neu dem tam = 0 thi nhap sai
            for (int i=0; i<size; i++)
            {
                if ( maTam==listHH[i].maHH)
                {
                    listHH[i].hienThiThongTin();
                    demTam++;
                    break;
                }
            }
            if (demTam==0)
            {
                cout << "Ma hang hoa khong ton tai!" << endl;
            }
            returnfindHHMenu();
            cout << "Nhap lua chon: ";
        }
        else if (timKiem==2)
        {
            system("cls");
            string maTenTam;// nhap ten hang hoa muon tim kiem
            cout << "CHE DO TIM KIEM THEO TEN HANG HOA\n";
            cout << "____________________________________________" << endl;
            cout << "Nhap ten hang hoa muon tim kiem: ";
            do
            {
                getline(cin,maTenTam);
            }
            while (maTenTam.length()==0);
            maTenTam = format(maTenTam);
            int demTam=0;// neu dem tam = 0 thi nhap sai
            for (int i=0; i<size; i++)
            {
                if ( maTenTam==listHH[i].tenHangHoa)
                {
                    listHH[i].hienThiThongTin();
                    demTam++;
                    break;
                }
            }
            if (demTam==0)
            {
                cout << "Ten hang hoa khong ton tai!" << endl;
            }
            returnfindHHMenu();
            cout << "Nhap lua chon: ";
        }
        else if (timKiem==0)
        {
            system("cls");
            mainMenu();
            break;
        }
    }
    while (true);
}
void HangHoa::sapXepThongTin()
{
    layDuLieu();
    cout << "Nhap lua chon: ";
    do
    {
        int sapXep;
        do
        {
            sapXep = nhapSo();
            if (sapXep<0 || sapXep>5)
            {
                cout << "Khong hop le vui long nhap lai: ";
            }
        }
        while (sapXep<0 || sapXep>5);
        if (sapXep==1)
        {
            for (int i=0; i<size; i++)
            {
                for (int j=i+1; j<size; j++)
                {
                    if (listHH[j].tenHangHoa<listHH[i].tenHangHoa)
                    {
                        swap(listHH[j],listHH[i]);
                    }
                }
            }
        }
        else if (sapXep==2)
        {
            for (int i=0; i<size; i++)
            {
                for (int j=i+1; j<size; j++)
                {
                    if (listHH[j].soLuong<listHH[i].soLuong)
                    {
                        swap(listHH[j],listHH[i]);
                    }
                }
            }
        }
        else if (sapXep==3)
        {
            for (int i=0; i<size; i++)
            {
                for (int j=i+1; j<size; j++)
                {
                    if (listHH[j].gia<listHH[i].gia)
                    {
                        swap(listHH[j],listHH[i]);
                    }
                }
            }
        }
        else if (sapXep==4)
        {
            int *tongNgay= new int [size];
            for (int i=0; i<size; i++)
            {
                tongNgay[i]=listHH[i].ngayNhap.getTongNgay();
            }
            for (int i=0; i<size; i++)
            {
                for (int j=i+1; j<size; j++)
                {
                    if (tongNgay[j]<tongNgay[i])
                    {
                        swap(tongNgay[j], tongNgay[i]);
                        swap(listHH[j], listHH[i]);
                    }
                }
            }
        }
        else if (sapXep==5)
        {
            int *tongNgay= new int [size];
            for (int i=0; i<size; i++)
            {
                tongNgay[i]=listHH[i].hanSuDung.getTongNgay();
            }
            for (int i=0; i<size; i++)
            {
                for (int j=i+1; j<size; j++)
                {
                    if (tongNgay[j]<tongNgay[i])
                    {
                        swap(tongNgay[j], tongNgay[i]);
                        swap(listHH[j],listHH[i]);
                    }
                }
            }
        }
        else if (sapXep==0)
        {
            system("cls");
            mainMenu();
            break;
        }
        luuThongTin();
        system("cls");
        cout << "DANH SACH HANG HOA SAU KHI SAP XEP" << endl;
        cout << "____________________________________________" << endl;
        display();
        returnsapXepHHMenu();
        cout << "Nhap lua chon: ";
    }
    while (true);
}
//Lop khach hang
class KhachHang : public ThongTin
{
private:
    string maKhachHang;
    string tenKhachHang;
    string soDienThoai;
    int diemTichLuy;
    KhachHang *listKH;
    int size=0;
public:
    KhachHang ();
    KhachHang (const KhachHang &other);
    void layDuLieu();
    void luuThongTin();
    void nhapThongTin();
    void hienThiThongTin();
    void input();
    void display();
    void capNhapThongTin();
    void themThongTin();
    void xoaThongTin();
    void timKiemThongTin();
    void sapXepThongTin();
};
//Cac ham trien khai ngoai lop
KhachHang::KhachHang ()
{
    listKH = nullptr;
    size = 0;
}
KhachHang::KhachHang (const KhachHang &other)
{
    this->maKhachHang = other.maKhachHang;
    this->tenKhachHang = other.tenKhachHang;
    this->soDienThoai = other.soDienThoai;
    this->diemTichLuy = other.diemTichLuy;
}
void KhachHang::layDuLieu()
{
    ifstream fi ("KhachHang.txt");
    fi >> this->size;
    listKH = new KhachHang[this->size];
    for (int i=0; i<this->size; i++)
    {
        do
        {
            getline(fi, listKH[i].maKhachHang);
        }
        while (listKH[i].maKhachHang.length()==0);
        do
        {
            getline(fi, listKH[i].tenKhachHang);
        }
        while (listKH[i].tenKhachHang.length()==0);
        do
        {
            getline(fi, listKH[i].soDienThoai);
        }
        while (listKH[i].soDienThoai.length()==0);
        fi >> listKH[i].diemTichLuy;
    }
    fi.close();
}
void KhachHang::luuThongTin()
{
    ofstream fo ("KhachHang.txt");
    fo << this->size << endl;
    for (int i=0; i<this->size; i++)
    {
        fo << listKH[i].maKhachHang << endl;
        fo << format(listKH[i].tenKhachHang) << endl;
        fo << listKH[i].soDienThoai << endl;
        fo << listKH[i].diemTichLuy << endl;
    }
    fo.close();
}
void KhachHang::nhapThongTin()
{
    layDuLieu();
    cout << "Ma khach hang: ";
    string *tam=new string [this->size];
    for (int i=0; i<size; i++)
    {
        tam[i]=listKH[i].maKhachHang;
    }
    do
    {
        do
        {
            getline(cin, maKhachHang);
        }
        while (maKhachHang.length()==0);
        if (kiemTraMa(maKhachHang)==false)
        {
            cout << "Khong hop le vui long nhap lai: ";
        }
        else if (kiemTraMaTrung(tam,maKhachHang,size)==false)
        {
            cout<<"Ma khach hang da ton tai vui long nhap lai: ";
        }
    }
    while(kiemTraMa(maKhachHang)==false||kiemTraMaTrung(tam,maKhachHang,size)==false);


    cout << "Ten khach hang: ";
    do
    {
        do
        {
            getline(cin, tenKhachHang);
        }
        while (tenKhachHang.length()==0);
        if (kiemTraKyTu(tenKhachHang)==false)
        {
            cout << "Khong hop le vui long nhap lai: ";
        }
        else if (tenKhachHang.length()>25)
        {
            cout << "Ten qua dai vui long nhap lai co the ghi tat: ";
        }
    }
    while (kiemTraKyTu(tenKhachHang)==false || tenKhachHang.length() > 25);
    this->tenKhachHang = format(this->tenKhachHang);

    cout << "So dien thoai: ";
    string *SDTT = new string [this->size];
    for (int i=0; i<this->size; i++)
    {
        SDTT[i] = listKH[i].soDienThoai;
    }
    do
    {
        do
        {
            getline(cin, soDienThoai);
        }
        while (soDienThoai.length()==0);
        if (kiemTraSDT(soDienThoai)==false)
        {
            cout << "Khong hop le vui long nhap lai ";
        }
        else if (kiemTraMaTrung(SDTT, soDienThoai, size)==false)
        {
            cout << "So dien thoai da ton tai vui long nhap lai: ";
        }
    }
    while(kiemTraSDT(soDienThoai)==false || kiemTraMaTrung(SDTT, soDienThoai, size)==false);

    cout << "Diem tich luy: ";
    diemTichLuy = nhapSo();
}
void KhachHang::hienThiThongTin()
{
    cout << "Ma khach hang: " << this->maKhachHang << endl;
    cout << "Ten khach hang: " << format(this->tenKhachHang) << endl;
    cout << "So dien thoai: " << this->soDienThoai << endl;
    cout << "Diem tich luy: " << this->diemTichLuy << endl;
}
void KhachHang::input()
{
    layDuLieu();
    cout << "Nhap so luong khach hang muon nhap vao: ";
    int temp = nhapSo();
    KhachHang *khtemp = new KhachHang [this->size+temp];
    string *tam=new string [this->size+temp];
    string *SDTT = new string [this->size+temp];
    for (int i=0; i<this->size; i++)
    {
        khtemp[i] = listKH[i];
        tam[i] = listKH[i].maKhachHang;
        SDTT[i] = listKH[i].soDienThoai;
    }
    for (int i=0; i<temp; i++)
    {
        cout << "Khach hang thu " << i+1 << endl;
        cout << "Ma khach hang: ";
    do
    {
        do
        {
            getline(cin, khtemp[this->size+i].maKhachHang);
        }
        while (khtemp[this->size+i].maKhachHang.length()==0);
        if (kiemTraMa(khtemp[this->size+i].maKhachHang)==false)
        {
            cout << "Khong hop le vui long nhap lai: ";
        }
        else if (kiemTraMaTrung(tam,khtemp[this->size+i].maKhachHang,size+temp)==false)
        {
            cout<<"Ma khach hang da ton tai vui long nhap lai: ";
        }
    }
    while(kiemTraMa(khtemp[this->size+i].maKhachHang)==false||kiemTraMaTrung(tam,khtemp[this->size+i].maKhachHang,size+temp)==false);
    tam[this->size+i] = khtemp[this->size+i].maKhachHang;

    cout << "Ten khach hang: ";
    do
    {
        do
        {
            getline(cin, khtemp[this->size+i].tenKhachHang);
        }
        while (khtemp[this->size+i].tenKhachHang.length()==0);
        if (kiemTraKyTu(khtemp[this->size+i].tenKhachHang)==false)
        {
            cout << "Khong hop le vui long nhap lai: ";
        }
        else if (khtemp[this->size+i].tenKhachHang.length()>25)
        {
            cout << "Ten qua dai vui long nhap lai co the ghi tat: ";
        }
    }
    while (kiemTraKyTu(khtemp[this->size+i].tenKhachHang)==false || khtemp[this->size+i].tenKhachHang.length() > 25);
    khtemp[this->size+i].tenKhachHang = format(khtemp[this->size+i].tenKhachHang);

    cout << "So dien thoai: ";
    do
    {
        do
        {
            getline(cin, khtemp[this->size+i].soDienThoai);
        }
        while (khtemp[this->size+i].soDienThoai.length()==0);
        if (kiemTraSDT(khtemp[this->size+i].soDienThoai)==false)
        {
            cout << "Khong hop le vui long nhap lai ";
        }
        else if (kiemTraMaTrung(SDTT, khtemp[this->size+i].soDienThoai, size+temp)==false)
        {
            cout << "So dien thoai da ton tai vui long nhap lai: ";
        }
    }
    while(kiemTraSDT(khtemp[this->size+i].soDienThoai)==false || kiemTraMaTrung(SDTT, khtemp[this->size+i].soDienThoai, size+temp)==false);
    SDTT[this->size+i] = khtemp[this->size+i].soDienThoai;

    cout << "Diem tich luy: ";
    khtemp[this->size+i].diemTichLuy = nhapSo();
        cout << "____________________________________________" << endl;
    }
    delete [] listKH;
    listKH = khtemp;
    this->size=this->size+temp;
    cout << "Nhap thanh cong!" << endl;
}
void KhachHang::display()
{
    layDuLieu();
    cout << "+-----+" << "--------------+" << "----------------------+" << "-----------------+" << "-----------------+"  << endl;
    cout << "| STT |" << " Ma khach hang|" << "     Ten khach hang   |" << "  So dien thoai  |" << "  Diem tich luy  |" << endl;
    for (int i=0; i<this->size; i++)
    {
        cout << "+-----+" << "--------------+" << "----------------------+" << "-----------------+" << "-----------------+"  << endl;
        cout << "|" << i+1;
        string iT = to_string(i+1);
        cout.width(6-iT.length());
        cout << "|";
        cout<<listKH[i].maKhachHang;
        cout.width(15-listKH[i].maKhachHang.length());
        cout << "|";
        cout << format(listKH[i].tenKhachHang);
        cout.width(23-listKH[i].tenKhachHang.length());
        cout << "|";
        cout << listKH[i].soDienThoai;
        cout.width(18-listKH[i].soDienThoai.length());
        cout << "|";
        cout << listKH[i].diemTichLuy;
        string iT1 = to_string(listKH[i].diemTichLuy);
        cout.width(18-iT1.length());
        cout << "|"<<endl;
    }
    cout << "+-----+" << "--------------+" << "----------------------+" << "-----------------+" << "-----------------+"  << endl;
}
void KhachHang::capNhapThongTin()
{
    display();
    cout << "Nhap ma hoac ten khach hang: ";
    string temp;
    do
    {
        getline(cin, temp);
    }
    while (temp.length()==0);
    temp = format(temp);
    int viTri=0;
    int demTam=0;
    for (int i=0; i<size; i++)
    {
        if ( temp==listKH[i].maKhachHang || temp==listKH[i].tenKhachHang)
        {
            viTri = i;
            demTam++;
            break;
        }
    }
    if (demTam==0)
    {
        cout << "Ma hoac ten khach hang khong ton tai!" << endl;
    }
    else
    {
        system("cls");
        listKH[viTri].hienThiThongTin();
        cout << "____________________________________________" << endl;
        cout << "1. Ten khach hang" << endl;
        cout << "2. So dien thoai" << endl;
        cout << "3. Diem tich luy" << endl;
        cout << "____________________________________________" << endl;
        cout << "Lua chon thong tin muon cap nhap: ";
        int luaChon=0;
        do
        {
            do
            {
                luaChon = nhapSo();
                if (luaChon<1 || luaChon>3)
                {
                    cout << "Khong hop le vui long nhap lai: ";
                }
            }
            while (luaChon<1 || luaChon>3);
            if (luaChon==1)
            {
                cout << "Nhap ten khach hang moi: ";
                do
                {
                    do
                    {
                        getline(cin, listKH[viTri].tenKhachHang);
                    }
                    while (listKH[viTri].tenKhachHang.length()==0);
                    if (kiemTraKyTu(listKH[viTri].tenKhachHang)==false)
                    {
                        cout << "Khong hop le vui long nhap lai: ";
                    }
                }
                while (kiemTraKyTu(listKH[viTri].tenKhachHang)==false);
                listKH[viTri].tenKhachHang = format(listKH[viTri].tenKhachHang);
                break;
            }
            else if (luaChon==2)
            {
                string *sdttam = new string [this->size];
                for (int i=0; i< this->size; i++)
                {
                    sdttam[i] = listKH[i].soDienThoai;
                }
                cout << "Nhap so dien thoai moi: ";
                do
                {
                    do
                    {
                        getline(cin, listKH[viTri].soDienThoai);
                    }
                    while (listKH[viTri].soDienThoai.length()==0);
                    if (kiemTraSDT(listKH[viTri].soDienThoai)==false)
                    {
                        cout << "Khong hop le vui long nhap lai ";
                    }
                    else if (kiemTraMaTrung(sdttam, listKH[viTri].soDienThoai, size)==false)
                    {
                        cout << "So dien thoai da ton tai vui long nhap lai: ";
                    }
                }
                while(kiemTraSDT(listKH[viTri].soDienThoai)==false || kiemTraMaTrung(sdttam, listKH[viTri].soDienThoai, size)==false);
                break;
            }
            else if (luaChon==3)
            {
                cout << "Nhap diem tich luy moi: ";
                listKH[viTri].diemTichLuy = nhapSo();
                break;
            }
        }
        while (true);
    }
    cout << "Cap nhap thong tin khach hang thanh cong!" << endl;
    luuThongTin();
}
void KhachHang::themThongTin()
{
    display();
    cout << "Nhap vi tri muon them khach hang: ";
    int viTri;
    do
    {
        viTri = nhapSo();
        if (viTri<1 || viTri>this->size)
        {
            cout << "Khong hop le vui long nhap lai: ";
        }
    }
    while (viTri<1 || viTri>this->size);
    viTri--;
    this->size=this->size+1;
    KhachHang *khtempT = new KhachHang [this->size];
    khtempT[viTri].nhapThongTin();
    for (int i=0; i<viTri; i++)
    {
        khtempT[i] = listKH[i];
    }
    for (int i=viTri+1; i<this->size; i++)
    {
        khtempT[i] = listKH[i-1];
    }
    delete [] listKH;
    listKH = khtempT;
    luuThongTin();
    system("cls");
    cout << "DANH SACH KHACH HANG SAU KHI THEM" << endl;
    cout << "____________________________________________" << endl;
    display();
    cout << "Them khach hang thanh cong!" << endl;
}
void KhachHang::xoaThongTin()
{
    display();
    cout << "Nhap vi tri muon xoa: ";
    int viTri;
    do
    {
        viTri = nhapSo();
        if (viTri<1 || viTri>this->size)
        {
            cout << "Khong hop le vui long nhap lai: ";
        }
    }
    while (viTri<1 || viTri>this->size);
    viTri--;
    this->size--;
    KhachHang *listKHTemp = new KhachHang [this->size];
    for (int i=0; i<viTri; i++)
    {
        listKHTemp[i] = listKH[i];
    }
    for (int i=viTri; i<this->size; i++)
    {
        listKHTemp[i] = listKH[i+1];
    }
    delete [] listKH;
    listKH = listKHTemp;
    luuThongTin();
    system("cls");
    cout << "DANH SACH KHACH HANG SAU KHI XOA\n";
    cout << "____________________________________________" << endl;
    display();
    cout << "Xoa khach hang thanh cong!" << endl;
}
void KhachHang::timKiemThongTin()
{
    layDuLieu();
    cout << "Nhap lua chon: ";
    do
    {
        int timKiem;
        do
        {
            timKiem = nhapSo();
            if (timKiem<0||timKiem>2)
            {
                cout<<"Khong hop le vui long nhap lai: ";
            }
        }
        while(timKiem<0||timKiem>2);
        if (timKiem==1)
        {
            system("cls");
            cout << "CHE DO TIM KIEM THEO MA KHACH HANG\n";
            cout << "____________________________________________" << endl;
            string maTam; //nhap ma khach hang muon tim kiem
            cout<<"Nhap ma khach hang muon tim kiem: ";
            do
            {
                getline(cin,maTam);
            }
            while(maTam.length()==0);
            int demTam=0;// neu dem tam = 0 thi nhap sai
            for (int i=0; i<size; i++)
            {
                if ( maTam==listKH[i].maKhachHang)
                {
                    listKH[i].hienThiThongTin();
                    demTam++;
                    break;
                }
            }
            if (demTam==0)
            {
                cout << "Ma khang hang khong ton tai!" << endl;
            }
            returnfindKHMenu();
            cout << "Nhap lua chon: ";
        }
        else if (timKiem==2)
        {
            system("cls");
            cout << "CHE DO TIM KIEM THEO TEN KHACH HANG\n";
            cout << "____________________________________________" << endl;
            string maTenTam;// nhap ten hang hoa muon tim kiem
            cout << "Nhap ten khach hang muon tim kiem: ";
            do
            {
                getline(cin,maTenTam);
            }
            while(maTenTam.length()==0);
            maTenTam = format(maTenTam);
            int demTam=0;// neu dem tam = 0 thi nhap sai
            for (int i=0; i<size; i++)
            {
                if ( maTenTam==listKH[i].tenKhachHang)
                {
                    listKH[i].hienThiThongTin();
                    demTam++;
                    break;
                }
            }
            if (demTam==0)
            {
                cout << "Ten khach hang khong ton tai!" << endl;
            }
            returnfindKHMenu();
            cout << "Nhap lua chon: ";
        }
        else if (timKiem==0)
        {
            system("cls");
            mainMenu();
            break;
        }
    }
    while(true);
}
void KhachHang::sapXepThongTin()
{
    layDuLieu();
    cout << "Nhap lua chon: ";
    do
    {
        int luaChon;
        do
        {
            luaChon = nhapSo();
            if (luaChon<0 || luaChon>2)
            {
                cout << "Khong hop le vui long nhap lai: ";
            }
        }
        while (luaChon<0 || luaChon>2);
        if (luaChon==1)
        {
            for (int i=0; i<size; i++)
            {
                for (int j=i+1; j<size; j++)
                {
                    if (listKH[j].tenKhachHang<listKH[i].tenKhachHang)
                    {
                        swap(listKH[j],listKH[i]);
                    }
                }
            }
        }
        else if (luaChon==2)
        {
            for (int i=0; i<size; i++)
            {
                for (int j=i+1; j<size; j++)
                {
                    if (listKH[j].diemTichLuy<listKH[i].diemTichLuy)
                    {
                        swap(listKH[j],listKH[i]);
                    }
                }
            }
        }
        else if (luaChon==0)
        {
            system("cls");
            mainMenu();
            break;
        }
        luuThongTin();
        system("cls");
        cout << "DANH SACH KHACH HANG SAU KHI SAP XEP" << endl;
        cout << "____________________________________________" << endl;
        display();
        returnsapXepKHMenu();
        cout << "Nhap lua chon: ";
    }
    while (true);
}
int main()
{
    ThongTin *tt[2];
    tt[0] = new HangHoa();
    tt[1] = new KhachHang();
    //Menu chinh
    cout << "CHUONG TRINH QUAN LY CUA HANG\n";
    mainMenu();
    do
    {
        int n;
        cout << "Nhap lua chon: ";
        do
        {
            n = nhapSo();
            if (n<0 || n>14)
            {
                cout << "Khong hop le vui long nhap lai: ";
            }
        }
        while (n<0 || n>14);
        if (n==1)
        {
            system("cls");
            cout << "CHE DO NHAP HANG HOA\n";
            cout << "____________________________________________" << endl;
            tt[0]->input();
            tt[0]->luuThongTin();
            returnMainMenu();
        }
        else if (n==2)
        {
            system("cls");
            cout << "CHE DO NHAP THONG TIN KHACH HANG\n";
            cout << "____________________________________________" << endl;
            tt[1]->input();
            tt[1]->luuThongTin();
            returnMainMenu();
        }
        else if (n==3)
        {
            system("cls");
            cout << "CHE DO HIEN THI DANH SACH HANG HOA" << endl;
            tt[0]->display();
            returnMainMenu();
        }
        else if (n==4)
        {
            system("cls");
            cout << "CHE DO HIEN THI DANH SACH KHACH HANG" << endl;

            tt[1]->display();
            returnMainMenu();
        }
        else if (n==5)
        {
            system("cls");
            cout << "CHE DO CAP NHAP THONG TIN HANG HOA" << endl;
            cout << "____________________________________________" << endl;
            tt[0]->capNhapThongTin();
            returnMainMenu();
        }
        else if (n==6)
        {
            system("cls");
            cout << "CHE DO CAP NHAP THONG TIN KHACH HANG" << endl;
            cout << "____________________________________________" << endl;
            tt[1]->capNhapThongTin();
            returnMainMenu();
        }
        else if (n==7)
        {
            system("cls");
            cout << "CHE DO THEM THONG TIN HANG HOA\n";
            cout << "____________________________________________" << endl;
            tt[0]->themThongTin();
            returnMainMenu();
        }
        else if (n==8)
        {
            system("cls");
            cout << "CHE DO THEM THONG TIN KHACH HANG\n";
            cout << "____________________________________________" << endl;
            tt[1]->themThongTin();
            returnMainMenu();
        }
        else if (n==9)
        {
            system("cls");
            cout << "CHE DO XOA THONG TIN HANG HOA\n";
            cout << "___________________________________________" << endl;
            tt[0]->xoaThongTin();
            returnMainMenu();
        }
        else if (n==10)
        {
            system("cls");
            cout << "CHE DO XOA THONG TIN KHACH HANG\n";
            cout << "___________________________________________" << endl;
            tt[1]->xoaThongTin();
            returnMainMenu();
        }
        else if (n==11)
        {
            system("cls");
            cout << "CHE DO TIM KIEM THONG TIN HANG HOA\n";
            cout << "____________________________________________" << endl;
            findHHMenu();
            tt[0]->timKiemThongTin();
        }
        else if (n==12)
        {
            system("cls");
            cout << "CHE DO TIM KIEM THONG TIN KHACH HANG\n";
            cout << "____________________________________________" << endl;
            findKHMenu();
            tt[1]->timKiemThongTin();
        }
        else if (n==13)
        {
            system("cls");
            cout << "CHE DO SAP XEP THONG TIN HANG HOA\n";
            cout << "____________________________________________" << endl;
            sapXepHHMenu();
            tt[0]->sapXepThongTin();
        }
        else if (n==14)
        {
            system("cls");
            cout << "CHE DO SAP XEP THONG TIN KHACH HANG\n";
            cout << "____________________________________________" << endl;
            sapXepKHMenu();
            tt[1]->sapXepThongTin();
        }
        else if (n==0)
        {
            break;
        }
    }
    while (true);
    cout << "Ban da thoat khoi ung dung!";
    return 0;
}

