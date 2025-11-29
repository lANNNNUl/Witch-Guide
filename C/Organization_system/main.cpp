#include <stdio.h>
#include <iostream>
#include <windows.h>
#include <vector>
using namespace std;

class mahou_shoujo
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

    string get_phonenumber(size_t index) const
    {
        if (index < phonenumber.size()){
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

    void init_majo(string nameget,string addressget,string phonenumberget)
    {
        name=nameget,address=addressget,phonenumber.push_back(phonenumberget);
    }

    void rename_majo(string new_name)
    {
        name=new_name;
    }

    void rewirte_address(string new_address)
    {
        address=new_address;
    }

    void delete_majophonenumber(size_t index)
    {
        if (index < phonenumber.size())
        {
            phonenumber.erase(phonenumber.begin() + index);
        }
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

vector<mahou_shoujo> mahou_shoujolist;

void findmahou_shoujo()
{
    cout << "根据名字查找请输入1\n";
    cout << "根据电话号码查找请输入2\n";
    int user_choice;
    cin >> user_choice;

    if (user_choice == 1) {
        cout << "请输入魔女姓名：\n";
        string name;
        cin >> name;

        for (const auto& cp : mahou_shoujolist) {    
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

void modifymahou_shoujo()
{
    cout << "输入想要修改的魔女序号:\n";

    // 列出所有魔女（带序号）
    for (size_t contactIdx = 0; contactIdx < mahou_shoujolist.size(); ++contactIdx)
    {
        const auto& cp = mahou_shoujolist[contactIdx];
        cout << contactIdx << ". " << cp.get_name() << '\n';
    }

    // 用户输入序号
    size_t userChoice= -1;
    //默认无效
    cin >> userChoice;

    while(true){
        if (userChoice >= mahou_shoujolist.size() )
        {
        cout << "无效的魔女序号！\n";
        return;
        }
        cout << "选择想要修改的信息:\n" ;
        cout << "1.姓名 2.地址 3.电话号码 0.返回主界面\n" ;
        size_t infoChoice = -1;
        cin >> infoChoice;
        if(infoChoice == 0){
            break;
        }else if (infoChoice == 1)
        {
            string new_name;
            cout << "请输入新的姓名:\n";
            cin >> new_name;
            mahou_shoujolist[userChoice].rename_majo(new_name);
        }
        else if (infoChoice == 2)
        {
            string new_address;
            cout << "请输入新的地址:\n";
            cin >> new_address;
            mahou_shoujolist[userChoice].rewirte_address(mahou_shoujolist[userChoice].get_name());
        }
        else if (infoChoice == 3)
        {
            cout << "当前电话号码有:\n";
            mahou_shoujolist[userChoice].show_phonenumbers();
            cout << "选择操作: 1.添加电话号码 2.删除电话号码\n";
            size_t phoneChoice = -1;
            cin >> phoneChoice;
            if (phoneChoice == 1)
            {
                string new_phonenumber;
                cout << "请输入新的电话号码:\n";
                cin >> new_phonenumber;
                mahou_shoujolist[userChoice].add_phonenumber(new_phonenumber);
            }
            else if (phoneChoice == 2)
            {
                cout << "请输入要删除的电话号码索引(从0开始):\n";
                size_t delIndex = -1;
                cin >> delIndex;
                mahou_shoujolist[userChoice].delete_majophonenumber(delIndex);
            }
        }
        
    }
    

    cout << "魔女信息已更新。\n";
}

void addmahou_shoujo(){
    string name,address,phonenumber;
    cout << "请输入魔女姓名：" << endl;
    cin >> name;
    cout << "请输入魔女地址：" << endl;
    cin >> address;
    cout << "请输入魔女电话号码：" << endl;
    cin >> phonenumber;
    mahou_shoujo contact_temp;
    contact_temp.init_majo(name,address,phonenumber);
    mahou_shoujolist.push_back(contact_temp);
    cout << "魔女添加成功！" << endl;
}

void clearAllmahou_shoujo()
{
    mahou_shoujolist.clear();
    cout << "所有魔女已清空！" << endl;
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

void deletemahou_shoujo()
{
    cout << "输入想要删除的魔女序号:\n";

    // 列出所有魔女（带序号）
    for (size_t contactIdx = 0; contactIdx < mahou_shoujolist.size(); ++contactIdx)
    {
        const auto& cp = mahou_shoujolist[contactIdx];
        cout << contactIdx << ". " << cp.get_name() << '\n';
    }

    // 用户输入序号
    size_t userChoice= -1;
    //默认无效
    cin >> userChoice;

    if (userChoice >= mahou_shoujolist.size() )
    {
        cout << "无效的魔女序号！\n";
        return;
    }

    // 删除所选魔女
    mahou_shoujolist.erase(mahou_shoujolist.begin() + userChoice);
    cout << "魔女已删除。\n";
}

void showmahou_shoujo()
{
    cout << "输入想要查询的魔女序号:\n";

    // 列出所有魔女（带序号）
    for (size_t contactIdx = 0; contactIdx < mahou_shoujolist.size(); ++contactIdx)
    {
        const auto& cp = mahou_shoujolist[contactIdx];
        cout << contactIdx << ". " << cp.get_name() << '\n';
    }

    // 用户输入序号
    size_t userChoice= -1;
    //默认无效
    cin >> userChoice;

    if (userChoice >= mahou_shoujolist.size())
    {
        cout << "无效的魔女序号！\n";
        return;
    }

    // 输出所选魔女详情
    const auto& cp = mahou_shoujolist[userChoice];
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

 void mahou_shoujoinit(){
    // 13 位魔法少女初始化
mahou_shoujo ema;      ema.init_majo("樱羽艾玛",    "三木谷奈奈",      "13800138000");
mahou_shoujo hiro;     hiro.init_majo("二阶堂希罗",  "東雲はる",        "13900139000");
mahou_shoujo coco;     coco.init_majo("泽渡可可",    "比良坂芽衣",      "13700137000");
mahou_shoujo shirley;  shirley.init_majo("橘雪莉",   "柊优花",          "13600136000");
mahou_shoujo hanna;    hanna.init_majo("远野汉娜",   "石崎纱彩",        "13500135000");
mahou_shoujo ann;      ann.init_majo("夏目安安",     "葵梓",            "13400134000");
mahou_shoujo noah;     noah.init_majo("城崎诺亚",   "井口裕香",        "13300133000");
mahou_shoujo reira;    reira.init_majo("莲见蕾雅",  "小清水亚美",      "13200132000");
mahou_shoujo miria;    miria.init_majo("佐伯米莉亚","高森奈津美",      "13100131000");
mahou_shoujo nayuka;   nayuka.init_majo("黑部奈叶香","大熊和奏",       "13000130000");
mahou_shoujo mag;      mag.init_majo("宝生玛格",    "树冬华",          "12900129000");
mahou_shoujo arisa;    arisa.init_majo("紫藤亚里沙","石井未纱",        "12800128000");
mahou_shoujo meruru;   meruru.init_majo("冰上梅露露","山下七海",        "12700127000");

mahou_shoujolist.emplace_back(ema);
mahou_shoujolist.emplace_back(hiro);
mahou_shoujolist.emplace_back(coco);
mahou_shoujolist.emplace_back(shirley);
mahou_shoujolist.emplace_back(hanna);
mahou_shoujolist.emplace_back(ann);
mahou_shoujolist.emplace_back(noah);
mahou_shoujolist.emplace_back(reira);
mahou_shoujolist.emplace_back(miria);
mahou_shoujolist.emplace_back(nayuka);
mahou_shoujolist.emplace_back(mag);
mahou_shoujolist.emplace_back(arisa);
mahou_shoujolist.emplace_back(meruru);

}

int main()
{   
    SetConsoleOutputCP(CP_UTF8);   // 输出 UTF-8
    SetConsoleCP(CP_UTF8); 
    int select = 0;
    mahou_shoujoinit();
    while(true){
    showmenu();
    cin >> select;
    if (select == 0) {                          // 退出
    cout << "欢迎下次再来。" << endl;
    return 0;
    }
    else if (select == 1) {                     // 1. 添加魔女
    addmahou_shoujo();
    }
    else if (select == 2) {                     // 2. 显示魔女
    showmahou_shoujo();
    }
    else if (select == 3) {                     // 3. 删除魔女
    deletemahou_shoujo();
    }
    else if (select == 4) {                     // 4. 查找魔女
    findmahou_shoujo();
    }
    else if (select == 5) {                     // 5. 修改魔女
    modifymahou_shoujo();
    }
    else if (select == 6) {                     // 6. 清空魔女
    clearAllmahou_shoujo();
    }
    }
    
    return 0;

}