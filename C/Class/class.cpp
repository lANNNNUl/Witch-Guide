#include<iostream>
#include<vector>
using namespace std;  

class shape{
    protected:
        string shape_name;
    private:
        int position_x, position_y;
    public:
        float area();
        bool draw();
};

class box{
    private:
        static int box_Id_counter;
        int box_Id;
        float length=0, width=0, height=0;
        string box_name = "default_box";
    public:

        void def_boxname(string name){
        box_name = name;
        }

        void def_boxsize(float l=1, float w=1, float h=1){
            length = l;
            width = w;
            height = h;
            box_Id = box_Id_counter;
            box_Id_counter++;
        }

        int get_box_id()
        {
            return box_Id;
        }

        string get_box_name()
        {
            return box_name;
        }

        float get_box_volume()
        {
            return length * width * height;
        }

};

int box::box_Id_counter = 1; 

int main()
{
    vector<box> boxlist;
    box zhang_box;
    box wang_box;
    box li_box;
    zhang_box.def_boxname("老张盒子");
    zhang_box.def_boxsize(1.1,2.2,3.3);
    wang_box.def_boxname("老王盒子");
    wang_box.def_boxsize(1.1,3.2,4.3);
    li_box.def_boxname("老李盒子");
    li_box.def_boxsize(6,6,6);
    boxlist.push_back(zhang_box);
    boxlist.push_back(wang_box);
    boxlist.push_back(li_box);
   for (size_t i = 0; i < boxlist.size(); ++i) {
    cout << "盒子名字" << boxlist[i].get_box_name() << endl;
    cout << "盒子ID:"   << boxlist[i].get_box_id()   << endl;
    cout << "盒子体积：" << boxlist[i].get_box_volume() << endl;
}
}