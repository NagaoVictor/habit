#include <stdio.h>
#include <sys/statvfs.h>



int main(){
	struct statvfs usage;
	
	if (statvfs("/", &usage) == -1){
		perror("データを読み込む際にえらーがはっせいしました\n");
		return 1;
	}

	unsigned long total_space = usage.f_blocks * usage.f_frsize;
	unsigned long free_space = usage.f_bavail * usage.f_frsize;
	unsigned long used_space = total_space - free_space;


	printf("--- スーパーブロックの報告 ---\n");
	printf("全容量: %lu\n", total_space);
	printf("使用量: %lu\n", free_space);
	printf("空き容量: %lu\n", used_space);



	printf("総iノーデ数 %lu\n", usage.f_files);
	printf("空きiノーデ数 %lu\n", usage.f_favail);
	
	return 0;




}
