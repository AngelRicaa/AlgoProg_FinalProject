#include <stdio.h>

long long sum(long long m){
	__int128 a = m;
    __int128 val = a * (a + 1) * (2*a + 1) / 6;
    return (long long) val;
}

long long search(long long m){
	long long left = 1, right = 2000000;
	long long result = right;
	
	while(left <= right){
		long long mid = (left+right)/2;
		
		if(sum(mid) >= m){
			result = mid;
			right = mid -1;
		}else{
			left = mid+1;
		}
	}	
	
	return result;
}

int main(){
	long long t, tc, i, j;
	long long n, m;
	
	scanf("%lld", &tc); getchar();
	for(t = 0; t < tc; t++){
		scanf("%lld", &m); getchar();
		
		long long hasil = search(m);
		printf("Case #%lld: %lld\n", t+1, hasil);
	}
	return 0;
}

#include <stdio.h>

int enough(long long n, long long m){
    long long s = 0;
    for(long long i = 1; i <= n; i++){
        s += i*i;
        if(s >= m) return 1;
    }
    return 0;
}

long long search(long long m){
    long long left = 1, right = 2000000, ans = right;
    while(left <= right){
        long long mid = (left + right) / 2;
        if(enough(mid, m)){
            ans = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return ans;
}

int main(){
    long long T, m;
    scanf("%lld", &T);
    for(long long t = 1; t <= T; t++){
        scanf("%lld", &m);
        long long n = search(m);
        printf("Case #%lld: %lld\n", t, n);
    }
    return 0;
}

