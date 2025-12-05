#include<iostream>
#include<random>
#include<vector>

using namespace std;

#define RUNTIMES 100

enum class StarType : std::uint16_t {
    SixStarsMain = 10,    
    SixStarsVice = 20,  
    SixStarsNormal =21,
    FiveStarsMain = 30,  
    FiveStarsNormal = 40,  
    FourStars = 50,      
    ThreeStars = 60       
};



class GambleBox{

    static constexpr double probability_six_stars_base = 2.0;
    static constexpr double probability_five_stars = 8.0;
    static constexpr double probability_four_stars = 30.0;

    private:
        double current_sixstars_probability = probability_six_stars_base;
        unsigned current_gamble_times = 0;
        unsigned six_stars_up=0;                //6当期
        unsigned six_stars_main=0;              //限定
        unsigned six_stars_vice=0;              //陪跑                      
        unsigned six_stars_low=0;               //歪了
        unsigned five_stars_high=0;             //5当期
        unsigned five_stars_low=0;              //歪了
        unsigned four_stars=0;
        unsigned three_stars=0;
        unsigned total_gamble_times = 0;
    public:

        static random_device rd;  // 随机设备
        static mt19937 gen;       // Mersenne Twister 伪随机数生成器
        vector<StarType> Gamble(unsigned times);
        void GambleBox_Reset();
        
};

vector<StarType> GambleBox::Gamble(unsigned wanted_times){
    uniform_real_distribution<> dis(0.0, 100.0);
    vector<StarType> result;
    for (unsigned i=0; i < wanted_times; ++i)
    {
        double random_numbers = dis(gen);
        current_gamble_times ++ ;
        if(current_gamble_times > 50)
        {
        current_sixstars_probability += 2;
        }

        if(random_numbers <= current_sixstars_probability)    //2% 六星
        {  
            current_gamble_times = 0 ;
            if(dis(gen) <= 50) //50% 当期六星
            {
                six_stars_up++;
                if(dis(gen) <= 50)
                    six_stars_main ++, result.push_back(StarType::SixStarsMain);
                else six_stars_vice ++,result.push_back(StarType::SixStarsVice);
            }
            else
            {
                six_stars_low++,result.push_back(StarType::SixStarsNormal);
            }
        }else if(random_numbers <= probability_five_stars)
        {
            if(dis(gen) >= 50) //50% 当期六星
            {
                five_stars_high++,result.push_back(StarType::FiveStarsMain);
            }
            else
            {
                five_stars_low++,result.push_back(StarType::FiveStarsNormal);
            }
        }else if(random_numbers <= probability_four_stars)
        {
            four_stars ++,result.push_back(StarType::FourStars);
        }else three_stars ++,result.push_back(StarType::ThreeStars);


    }

    
    
    return result;
}


string StarTypeToString(StarType type) {
    switch (type) {
        case StarType::SixStarsMain: return "主6";
        case StarType::SixStarsVice: return "副6";
        case StarType::SixStarsNormal: return "普6";
        case StarType::FiveStarsMain: return "5UP";
        case StarType::FiveStarsNormal: return "5普";
        case StarType::FourStars: return "4";
        case StarType::ThreeStars: return "3";
        default: return "?";
    }
}

// --- 重载 operator<< 用于输出 vector<StarType> ---
// 注意：这不是必须的，但可以让输出更简洁。
// 如果不定义这个，就需要手动循环打印。
ostream& operator<<(ostream& os, const vector<StarType>& vec) {
    os << "[";
    for (size_t i = 0; i < vec.size(); ++i) {
        os << StarTypeToString(vec[i]);
        if (i != vec.size() - 1) {
            os << ", "; // 元素之间用逗号和空格分隔
        }
    }
    os << "]";
    return os;
}

random_device GambleBox::rd;           
mt19937 GambleBox::gen(GambleBox::rd()); 

// --- 主函数 ---
int main() {
    GambleBox gb;
    string input;
    cout << "按回车键开始抽卡，输入 'q' 退出: ";

    while (getline(cin, input) && input != "q") {
        vector<StarType> results = gb.Gamble(10);
        for (size_t i = 0; i < results.size(); ++i) {
            cout << StarTypeToString(results[i]);
            if (i != results.size() - 1) {
                cout << ", ";
            }
            if ((i + 1) % 10 == 0 || i == results.size() - 1) {
                cout << "\n";
            }
        }
        
    }

    cout << "再见！" << endl;
    return 0;
}