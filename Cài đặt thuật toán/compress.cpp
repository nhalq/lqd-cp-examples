vector<int> values; 
for(int i = 1; i <= n; i++) values.push_back(arr[i]);
sort(values.begin(), values.end());
values.resize(unique(values.begin(), values.end()) - values.begin());

for(int i = 1; i <= n; i++)
	arr[i] = lower_bound(values.begin(), values.end(), arr[i]) - values.begin() + 1;
