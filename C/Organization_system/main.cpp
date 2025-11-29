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
        cout << "请输入魔女姓名：\n";
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
        cout << "请输入魔女电话号码：\n";
        cin >> phonenumber_demo;
        
    }

}

void modifyContactPerson()
{

}

void addContactPerson(){
    string name,address,phonenumber;
    cout << "请输入魔女姓名：" << endl;
    cin >> name;
    cout << "请输入魔女地址：" << endl;
    cin >> address;
    cout << "请输入魔女电话号码：" << endl;
    cin >> phonenumber;
    Contactperson contact_temp;
    contact_temp.init_contact(name,address,phonenumber);
    contactpersonlist.push_back(contact_temp);
    cout << "魔女添加成功！" << endl;
}

void clearAllContactPerson()
{

}

void showmenu()
{
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << "**********************" << endl;
    cout << "*******魔女图鉴********" << endl;
    cout << "*****1、添加魔女*******" << endl;
    cout << "*****2、显示魔女*******" << endl;
    cout << "*****3、删除魔女*******" << endl;
    cout << "*****4、查找魔女*******" << endl;
    cout << "*****5、修改魔女*******" << endl;
    cout << "*****6、清空魔女*******" << endl;
    cout << "****0、退出魔女图鉴*****" << endl;
    cout << "***********************" << endl;
}

void deleteContactPerson()
{
    cout << "输入想要删除的魔女序号:\n";

    // 列出所有魔女（带序号）
    for (size_t contactIdx = 0; contactIdx < contactpersonlist.size(); ++contactIdx)
    {
        const auto& cp = contactpersonlist[contactIdx];
        cout << contactIdx << ". " << cp.get_name() << '\n';
    }

    // 用户输入序号
    size_t userChoice= -1;
    //默认无效
    cin >> userChoice;

    if (userChoice >= contactpersonlist.size() )
    {
        cout << "无效的魔女序号！\n";
        return;
    }

    // 删除所选魔女
    contactpersonlist.erase(contactpersonlist.begin() + userChoice);
    cout << "魔女已删除。\n";
}

void showContactPerson()
{
    cout << "输入想要查询的魔女序号:\n";

    // 列出所有魔女（带序号）
    for (size_t contactIdx = 0; contactIdx < contactpersonlist.size(); ++contactIdx)
    {
        const auto& cp = contactpersonlist[contactIdx];
        cout << contactIdx << ". " << cp.get_name() << '\n';
    }

    // 用户输入序号
    size_t userChoice= -1;
    //默认无效
    cin >> userChoice;

    if (userChoice >= contactpersonlist.size() && userChoice < 0)
    {
        cout << "无效的魔女序号！\n";
        return;
    }

    // 输出所选魔女详情
    const auto& cp = contactpersonlist[userChoice];
    cout << "用户名字：" << cp.get_name() << '\n'
         << "用户地址：" << cp.get_address() << '\n'
         << "用户电话：";
    for (size_t i = 0; i < cp.get_phonenumber_amount(); ++i)
    {
        cout << cp.get_phonenumber(i);
        if (i + 1 < cp.get_phonenumber_amount()) cout << " | ";
    }
    cout << '\n';
}

 void contactpersoninit(){
    // 13 位魔法少女初始化
Contactperson ema;      ema.init_contact("樱羽艾玛",    "三木谷奈奈",      "13800138000");
Contactperson hiro;     hiro.init_contact("二阶堂希罗",  "東雲はる",        "13900139000");
Contactperson coco;     coco.init_contact("泽渡可可",    "比良坂芽衣",      "13700137000");
Contactperson shirley;  shirley.init_contact("橘雪莉",   "柊优花",          "13600136000");
Contactperson hanna;    hanna.init_contact("远野汉娜",   "石崎纱彩",        "13500135000");
Contactperson ann;      ann.init_contact("夏目安安",     "葵梓",            "13400134000");
Contactperson noah;     noah.init_contact("城崎诺亚",   "井口裕香",        "13300133000");
Contactperson reira;    reira.init_contact("莲见蕾雅",  "小清水亚美",      "13200132000");
Contactperson miria;    miria.init_contact("佐伯米莉亚","高森奈津美",      "13100131000");
Contactperson nayuka;   nayuka.init_contact("黑部奈叶香","大熊和奏",       "13000130000");
Contactperson mag;      mag.init_contact("宝生玛格",    "树冬华",          "12900129000");
Contactperson arisa;    arisa.init_contact("紫藤亚里沙","石井未纱",        "12800128000");
Contactperson meruru;   meruru.init_contact("冰上梅露露","山下七海",        "12700127000");

contactpersonlist.emplace_back(ema);
contactpersonlist.emplace_back(hiro);
contactpersonlist.emplace_back(coco);
contactpersonlist.emplace_back(shirley);
contactpersonlist.emplace_back(hanna);
contactpersonlist.emplace_back(ann);
contactpersonlist.emplace_back(noah);
contactpersonlist.emplace_back(reira);
contactpersonlist.emplace_back(miria);
contactpersonlist.emplace_back(nayuka);
contactpersonlist.emplace_back(mag);
contactpersonlist.emplace_back(arisa);
contactpersonlist.emplace_back(meruru);

}

int main()
{   
    SetConsoleOutputCP(CP_UTF8);   // 输出 UTF-8
    SetConsoleCP(CP_UTF8); 
    int select = 0;
    contactpersoninit();
    while(true){
    showmenu();
    cin >> select;
    if (select == 0) {                          // 退出
    cout << "欢迎下次再来。" << endl;
    return 0;
    }
    else if (select == 1) {                     // 1. 添加魔女
    addContactPerson();
    }
    else if (select == 2) {                     // 2. 显示魔女
    showContactPerson();
    }
    else if (select == 3) {                     // 3. 删除魔女
    deleteContactPerson();
    }
    else if (select == 4) {                     // 4. 查找魔女
    findContactPerson();
    }
    else if (select == 5) {                     // 5. 修改魔女
    modifyContactPerson();
    }
    else if (select == 6) {                     // 6. 清空魔女
    clearAllContactPerson();
    }
    }
    
    return 0;

}