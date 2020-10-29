void MoveStrings(vector<string>& source, vector<string>& destination ){

  int sourse_s = source.size();

  for (int i = 0; i < sourse_s; i++){
    destination.push_back(source[i]);
  }
  source.clear();
}
