bool IsPalindrom(std::string a){
  for (int i = 0;i < a.size();i++){
    if (a[i] != a[a.size()-1-i]){
      return false;
    }
  }
  return true;
}

std::vector<std::string> PalindromFilter(std::vector<std::string> input_v, int min_length){

  int input_v_size = input_v.size();
  std::vector<std::string> output_v;

  for(int i = 0; i < input_v_size; i++){
    if (IsPalindrom(input_v[i]) && (input_v[i].size() >= min_length) ){
      output_v.push_back(input_v[i]);
    }
  }

  return output_v;
}
