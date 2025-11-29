#include <stdio.h>
#include <iostream>
#include <windows.h>
#include <vector>
using namespace std;

class Contactperson
{
    private:
        string name;
        string address;
        vector<string>phonenumber;
    public:
    
    string get_address() const
    {
        return address;
    }
    string get_name() const
    {
        return name;
    }
    string get_phonenumber(int index) const
    {
        if (index >= 0 && index < phonenumber.size()){
            return phonenumber[index];
        }
        else{
            return "";
        }
    }

    unsigned get_phonenumber_amount() const
    {
        return phonenumber.size();
    }

    void init_contact(string nameget,string addressget,string phonenumberget)
    {
        name=nameget,address=addressget,phonenumber.push_back(phonenumberget);
    }
    void add_phonenumber(string new_phonenumber)
    {
        phonenumber.push_back(new_phonenumber);
    }

    void show_phonenumbers() const
    {
        for(const auto& phonenumbers_now:phonenumber)
        {
            cout << phonenumbers_now <<endl;
        }
    }

    bool ifmatchName(const string& key) const
     {
    return name == key;
}


};

vector<Contactperson> contactpersonlist;

void findContactPerson()
{
    cout << "根据名字查找请输入1\n";
    cout << "根据电话号码查找请输入2\n";
    int user_choice;
    cin >> user_choice;

    if (user_choice == 1) {
        cout << "请输入联系人姓名：\n";
        string name;
        cin >> name;

        for (const auto& cp : contactpersonlist) {    
            if (cp.ifmatchName(name)) {                  
                cout << "用户名字：" << cp.get_name() << '\n';
                cout << "用户地址：" << cp.get_address() << '\n';
                cout << "用户电话：";
                for (size_t i = 0; i < cp.get_phonenumber_amount(); ++i) {
                    cout << cp.get_phonenumber(i);
                    if (i + 1 < cp.get_phonenumber_amount()) cout << " | ";
                }
                cout << '\n';
            }
        }
    }
    else if (user_choice == 2) {
        string phonenumber_demo;
        cout << "请输入联系人电话号码：\n";
        cin >> phonenumber_demo;
        
    }

}

void modifyContactPerson()
{

}
void clearAllContactPerson()
{

}

void showmenu()
{

    cout << "**********************" << endl;
    cout << "*****1、添加联系人*****" << endl;
    cout << "*****2、显示联系人*****" << endl;
    cout << "*****3、删除联系人*****" << endl;
    cout << "*****4、查找联系人*****" << endl;
    cout << "*****5、修改联系人*****" << endl;
    cout << "*****6、清空联系人*****" << endl;
    cout << "*****0、退出通讯录*****" << endl;
    cout << "**********************" << endl;
}

int main()
{   
    SetConsoleOutputCP(CP_UTF8);   // 输出 UTF-8
    SetConsoleCP(CP_UTF8); 
    int select = 0;
    Contactperson li;
    li.init_contact("李四","北京市海淀区","13800138000");
    contactpersonlist.push_back(li);
    while(true){
    showmenu();
    cin >> select;
    if (select == 0) {                          // 退出
    cout << "欢迎下次再来。" << endl;
    return 0;
    }
    else if (select == 1) {                     // 1. 添加联系人
    //addContactPerson();
    }
    else if (select == 2) {                     // 2. 显示联系人
    //showContactPerson();
    }
    else if (select == 3) {                     // 3. 删除联系人
    //deleteContactPerson();
    }
    else if (select == 4) {                     // 4. 查找联系人
    findContactPerson();
    }
    else if (select == 5) {                     // 5. 修改联系人
    modifyContactPerson();
    }
    else if (select == 6) {                     // 6. 清空联系人
    clearAllContactPerson();
    }
    }
    
    return 0;

}