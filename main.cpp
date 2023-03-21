#include <iostream>
#include <cmath>

class Solution{
private:
    double eps;
    double left_border, right_border;
    double l;
    double x1, x2;
    double f1, f2;

    void PrintMethod() const
    {
        std::cout<<std::to_string(x1) + " " +std::to_string(x2)+" "+std::to_string(f1)+" "+std::to_string(f2)+" "+std::to_string(l)<<std::endl;
    }

    static double CalculateFunctionInPoint(double point)
    {
        return pow(cos(point), 4) - sqrt(std::abs(point+3));
    }

public:
    Solution()
    {
        eps = 0.001;
        left_border = -1.5;
        right_border = -0.5;
        l = right_border - left_border;
        x1 = left_border + 0.382*l;
        x2 = left_border + 0.618*l;
        f1 = CalculateFunctionInPoint(x1);
        f2 = CalculateFunctionInPoint(x2);
    }

    void MethodUsage()
    {
        PrintMethod();
        while(l>eps)
        {
            if(f1>f2)
            {
                left_border = x1;
                l = (right_border-left_border);
                x1 = x2;
                f1 = f2;
                x2 = left_border+ 0.618*l;
                f2 = CalculateFunctionInPoint(x2);
            }
            else if(f1<f2)
            {
                right_border = x2;
                l = right_border-left_border;
                x2 = x1;
                f2 = f1;
                x1 = left_border + 0.382*l;
                f1 = CalculateFunctionInPoint(x1);
            }
            else
            {
                left_border = x1;
                right_border = x2;
                l = right_border - left_border;
                x1 = left_border + 0.382*l;
                x2 = left_border+ 0.618*l;
                f1 = CalculateFunctionInPoint(x1);
                f2 = CalculateFunctionInPoint(x2);
            }
            PrintMethod();
        }
    }
    double FinalResult()
    {
        MethodUsage();
        return f1;
    }
};


int main() {
    Solution sol;
    std::cout << sol.FinalResult() << std::endl;
    return 0;
}
