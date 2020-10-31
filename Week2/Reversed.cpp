// Реализуйте функцию vector<int> Reversed(const vector<int>& v),
// возвращающую копию вектора v, в которой числа переставлены в обратном порядке.

vector<int> Reversed(const vector<int>& v){
    vector<int> output_v = v;

    auto beg = output_v.begin();
    auto en = output_v.end();

    while ((beg != en) && (beg != --en)) {
        std::iter_swap(beg++, en);
    }

    return output_v;
}
