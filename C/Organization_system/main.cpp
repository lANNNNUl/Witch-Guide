#include <iostream>
#include <vector>
#include <limits>
#include <string>
#include <windows.h>

using namespace std;

class mahou_shoujo {
private:
    string name;
    string address;
    vector<string> phonenumber;
    string notes;

public:
    string get_address() const {
        return address;
    }

    string get_name() const {
        return name;
    }

    string get_phonenumber(size_t index) const {
        if (index < phonenumber.size()) {
            return phonenumber[index];
        } else {
            return "";
        }
    }

    unsigned get_phonenumber_amount() const {
        return phonenumber.size();
    }

    void init_majo(string nameget, string addressget, string phonenumberget) {
        name = nameget;
        address = addressget;
        phonenumber.push_back(phonenumberget);
    }

    void rename_majo(string new_name) {
        name = new_name;
    }

    void rewirte_address(string new_address) {
        address = new_address;
    }

    void delete_majophonenumber(size_t index) {
        if (index < phonenumber.size()) {
            phonenumber.erase(phonenumber.begin() + index);
        }
    }

    void add_phonenumber(string new_phonenumber) {
        phonenumber.push_back(new_phonenumber);
    }

    void show_phonenumbers() const {
        for (const auto& phonenumbers_now : phonenumber) {
            cout << phonenumbers_now << endl;
        }
    }

    bool ifmatchName(const string& key) const {
        return name == key;
    }

    string read_notes() const {
        return notes;
    }

    void write_notes(const string& new_notes) {
        notes = new_notes;
    }

    void delete_notes() {
        notes.clear();
    }
};

size_t getValidIntegerInput() {
    size_t value;
    while (true) {
        cin >> value;
        if (!cin) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cerr << "无效输入，请输入一个有效的数字。\n";
        } else {
            return value;
        }
    }
}

vector<mahou_shoujo> mahou_shoujolist;

void show_all_mahou_shoujo() {
    cout << "魔女列表：" << endl;
    for (const auto& mahou_shoujo : mahou_shoujolist) {
        cout << "姓名: " << mahou_shoujo.get_name() << ", 地址: " << mahou_shoujo.get_address() << ", 电话号码: ";
        for (size_t i = 0; i < mahou_shoujo.get_phonenumber_amount(); ++i) {
            cout << mahou_shoujo.get_phonenumber(i);
            if (i + 1 < mahou_shoujo.get_phonenumber_amount()) cout << " | ";
        }
        if (mahou_shoujo.read_notes().empty()) {
            cout << ",备注: 无" << endl;
        } else {
            cout << ",备注:" << mahou_shoujo.read_notes() << endl;
        }
    }
}

void modifymahou_shoujo() {
    cout << "输入想要修改的魔女序号:\n";

    for (size_t contactIdx = 0; contactIdx < mahou_shoujolist.size(); ++contactIdx) {
        const auto& cp = mahou_shoujolist[contactIdx];
        cout << contactIdx << ". " << cp.get_name() << '\n';
    }

    size_t userChoice = getValidIntegerInput();

    if (userChoice >= mahou_shoujolist.size()) {
        cout << "无效的魔女序号！\n";
        return;
    }

    while (true) {
        cout << "选择想要修改的信息:\n";
        cout << "1.姓名 2.地址 3.电话号码 4.备注 0.返回主界面\n";
        size_t infoChoice = getValidIntegerInput();

        if (infoChoice == 0) {
            break;
        } else if (infoChoice == 1) {
            string new_name;
            cout << "请输入新的姓名:\n";
            cin >> new_name;
            mahou_shoujolist[userChoice].rename_majo(new_name);
        } else if (infoChoice == 2) {
            string new_address;
            cout << "请输入新的地址:\n";
            cin >> new_address;
            mahou_shoujolist[userChoice].rewirte_address(new_address);
        } else if (infoChoice == 3) {
            cout << "当前电话号码有:\n";
            mahou_shoujolist[userChoice].show_phonenumbers();
            cout << "选择操作: 1.添加电话号码 2.删除电话号码\n";
            size_t phoneChoice = getValidIntegerInput();

            if (phoneChoice == 1) {
                string new_phonenumber;
                cout << "请输入新的电话号码:\n";
                cin >> new_phonenumber;
                mahou_shoujolist[userChoice].add_phonenumber(new_phonenumber);
            } else if (phoneChoice == 2) {
                cout << "请输入要删除的电话号码索引(从0开始):\n";
                size_t delIndex = getValidIntegerInput();
                mahou_shoujolist[userChoice].delete_majophonenumber(delIndex);
            }
        } else if (infoChoice == 4) {
            cout << "当前备注内容为:\n" << mahou_shoujolist[userChoice].read_notes() << endl;
            cout << "选择操作: 1.修改备注 2.删除备注\n";
            size_t notesChoice = getValidIntegerInput();

            if (notesChoice == 1) {
                string new_notes;
                cout << "请输入新的备注内容:\n";
                cin >> new_notes;
                mahou_shoujolist[userChoice].write_notes(new_notes);
            } else if (notesChoice == 2) {
                mahou_shoujolist[userChoice].delete_notes();
            }
        }
    }

    cout << "魔女信息已更新。\n";
}

void addmahou_shoujo() {
    string name, address, phonenumber, notes;

    cout << "请输入魔女姓名：" << endl;
    cin >> name;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "请输入魔女地址：" << endl;
    getline(cin, address);

    cout << "请输入魔女电话号码：" << endl;
    getline(cin, phonenumber);

    cout << "请输入魔女备注信息（可选，回车键跳过）：" << endl;
    getline(cin, notes);

    mahou_shoujo contact_temp;
    contact_temp.init_majo(name, address, phonenumber);
    contact_temp.write_notes(notes);
    mahou_shoujolist.push_back(contact_temp);

    cout << "魔女添加成功！" << endl;
}

void clearAllmahou_shoujo() {
    mahou_shoujolist.clear();
    cout << "所有魔女已清空！" << endl;
}

void showmenu() {
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

void deletemahou_shoujo() {
    while (true) {
        cout << "输入想要删除的魔女序号:\n";
        for (size_t contactIdx = 0; contactIdx < mahou_shoujolist.size(); ++contactIdx) {
            const auto& cp = mahou_shoujolist[contactIdx];
            cout << contactIdx << ". " << cp.get_name() << '\n';
        }
        cout << "输入99999返回主界面\n";

        int userChoice = getValidIntegerInput();

        if (userChoice == 99999) {
            cout << "返回主界面。\n";
            break;
        } else if (userChoice < 0 || static_cast<size_t>(userChoice) >= mahou_shoujolist.size()) {
            cout << "无效的魔女序号！\n";
            continue;
        } else {
            cout << "确定要删除该魔女吗？(y/n): ";
            char confirm;
            cin >> confirm;
            if (confirm != 'y' && confirm != 'Y') {
                cout << "删除操作已取消。\n";
                continue;
            } else {
                mahou_shoujolist.erase(mahou_shoujolist.begin() + userChoice);
                cout << "魔女已删除。\n";
            }
        }
    }
}

void findmahou_shoujo() {
    cout << "输入想要查询的魔女序号:\n";
    for (size_t contactIdx = 0; contactIdx < mahou_shoujolist.size(); ++contactIdx) {
        const auto& cp = mahou_shoujolist[contactIdx];
        cout << contactIdx << ". " << cp.get_name() << '\n';
    }

    size_t userChoice = getValidIntegerInput();

    if (userChoice >= mahou_shoujolist.size()) {
        cout << "无效的魔女序号！\n";
        return;
    }

    const auto& cp = mahou_shoujolist[userChoice];
    cout << "姓名: " << cp.get_name() << ", 地址: " << cp.get_address() << ", 电话号码: ";
    for (size_t i = 0; i < cp.get_phonenumber_amount(); ++i) {
        cout << cp.get_phonenumber(i);
        if (i + 1 < cp.get_phonenumber_amount()) cout << " | ";
    }
    cout << ", 备注: " << cp.read_notes() << endl;
}

void mahou_shoujoinit() {
    mahou_shoujo ema; ema.init_majo("樱羽艾玛", "三木谷奈奈", "13800138000");
    mahou_shoujo hiro; hiro.init_majo("二阶堂希罗", "東雲はる", "13900139000");
    mahou_shoujo coco; coco.init_majo("泽渡可可", "比良坂芽衣", "13700137000");
    mahou_shoujo shirley; shirley.init_majo("橘雪莉", "柊优花", "13600136000");
    mahou_shoujo hanna; hanna.init_majo("远野汉娜", "石崎纱彩", "13500135000");
    mahou_shoujo ann; ann.init_majo("夏目安安", "葵梓", "13400134000");
    mahou_shoujo noah; noah.init_majo("城崎诺亚", "井口裕香", "13300133000");
    mahou_shoujo reira; reira.init_majo("莲见蕾雅", "小清水亚美", "13200132000");
    mahou_shoujo miria; miria.init_majo("佐伯米莉亚", "高森奈津美", "13100131000");
    mahou_shoujo nayuka; nayuka.init_majo("黑部奈叶香", "大熊和奏", "13000130000");
    mahou_shoujo mag; mag.init_majo("宝生玛格", "树冬华", "12900129000");
    mahou_shoujo arisa; arisa.init_majo("紫藤亚里沙", "石井未纱", "12800128000");
    mahou_shoujo meruru; meruru.init_majo("冰上梅露露", "山下七海", "12700127000");

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

int main() {
    SetConsoleOutputCP(CP_UTF8);   // 输出 UTF-8
    SetConsoleCP(CP_UTF8);         // 输入 UTF-8
    mahou_shoujoinit();

    while (true) {
        showmenu();
        size_t select = getValidIntegerInput();

        if (select == 0) {                          // 0. 退出魔女图鉴
            cout << "欢迎下次再来。" << endl;
            return 0;
        } else if (select == 1) {                   // 1. 添加魔女
            addmahou_shoujo();
        } else if (select == 2) {                   // 2. 显示魔女
            show_all_mahou_shoujo();
        } else if (select == 3) {                   // 3. 删除魔女
            deletemahou_shoujo();
        } else if (select == 4) {                   // 4. 查找魔女
            findmahou_shoujo();
        } else if (select == 5) {                   // 5. 修改魔女
            modifymahou_shoujo();
        } else if (select == 6) {                   // 6. 清空魔女
            clearAllmahou_shoujo();
        } else {
            cout << "无效的选择，请重新输入。" << endl;
        }
    }
}