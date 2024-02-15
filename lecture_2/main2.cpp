int main()
{

    int a = 3;
    int &b = a;
    const auto &b_1 = a;
    // int & const b_2 = a; //errors
    // int &const b_3 = a;

    return 0;
}