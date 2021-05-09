/*2020/06/23*/
/*セルを生成して二つのリストを作り、第1引数のリストが変更されないようにリストの連結をして連結されたリストを表示するプログラム*/
#include<stdio.h>
struct cell {
	int data;
	struct cell *next;
};
struct cell cell_pool[1000];
struct cell*new_cell=&cell_pool[0];;
/*セルを生成する関数
 *引数はdataとnext
 *戻り値は構造体cellを指すポインタ
↓テスト:mainに戻り値をcell1,cell2,cell3として表示させた。
	また、print_listでリストを表示させた。
 *引数にdataとnextを代入すると、cell1,cell2,cell3として4250528,4250536,4250544が出力された。
 *print_listの引数にcell3を代入すると、=>1=>5=>2が出力された。
　以上より、セルを生成して、そのセルを指すポインタを返していることが確認できた。
*/
struct cell*create_cell(int data,struct cell*next)
{
	struct cell*old_index;
	old_index=new_cell;
	new_cell++;
	old_index->data=data;
	old_index->next=next;
	return old_index;
}
/*繰り返しによってリストをたどって，各セルのdataメンバーを表示する関数
 *引数は構造体を指すポインタ
 *戻り値はない
↓テスト:mainで関数を呼び出し、表示させた.
   *引数にcell1を代入すると、=>2が出力された.
   *引数にcell2を代入すると、=>5=>2が出力された.
   *引数にcell3を代入すると、=>1=>5=>2が出力された.
   以上より、リストのを繰り返したどり、各セルのdataメンバーを表示することが確認できた。
*/
void print_list(struct cell*list)
{
	struct cell*p;
	p=list;
	while(p!=0){
		printf("=>%d",p->data);
		p= p->next;
	}
	printf("\n");
}

/*リストの終わりのセルを探す再帰関数
 *引数はリストの最初のセルへのポインタ
 *戻り値は見つかったセルへのポインタ
 ↓テスト:mainに戻り値をzとして表示させた.また、戻り値のポインタが指すセルのデータを表示させた。
   *引数にcell3を代入すると、4250528,2が出力された.
   *引数にcell4を代入すると、4250552,9が出力された。
   以上より、リストの終わりのセルが正しく探せていることが確認できた.
*/
struct cell* tail_list(struct cell*p)
{
	if(p->next==0)return p;
	else return tail_list(p->next);
}
/*二つのリストを連結する関数
 *引数は二つのリストのそれぞれのセルへの二つのポインタ
 *戻り値は連結されたリストの先頭のセルへのポインタ
 ↓テスト:mainに関数を呼び出し、戻り値をyとして表示させた。
　 また、戻り値のポインタが指すセルのデータを表示させた。
   さらに、print_listで確認した.
   *引数にcell3,cell5を代入すると、4250544,1が出力された.
   *引数にcell3,cell5を代入すると、print_list(y)で=>1=>5=>2=>3=>9が出力された.
   *引数にcell3,cell4を代入すると、4250544,1が出力された。
   *引数にcell3,cell4を代入すると、print_list(y)で=>1=>5=>2=>9が出力された。
   以上より、リストは連結され、また、戻り値として連結されたリストの先頭のセルへのポインタが返されていることが確認できた。
*/
struct cell*concat(struct cell*list1,struct cell*list2)
{
	struct cell*l;
	l=tail_list(list1);
	l->next=list2;
	
	return list1;
}
/*あるリストが引数に与えられたときに，これをコピーする関数
 *引数はリストのセルを指すポインタ
 *戻り値はリストのセルを指すポインタ
↓テスト:mainに戻り値をc1として表示させた.また、戻り値のポインタが指すセルのデータを表示させた。
   *引数にcell3を代入すると、4250640,1が出力された。
以上より、あるリストが引数に与えられたときに，これをコピーすることが確認できた。
*/
struct cell*copy(struct cell*c)
{
	if(c->next==0)return c;
	else return create_cell(c->data,copy(c->next));
}
/*第1引数のリストが変更されないように連結をする関数
 *引数は二つのリストのそれぞれのセルへの二つのポインタ
 *戻り値はない
 ↓テスト:mainに関数を呼び出し、戻り値をyとして表示させた。
　 また、戻り値のポインタが指すセルのデータを表示させた。
   さらに、print_listで確認した.
   *引数にcell3,cell5を代入すると、4250656,1が出力された.
   *引数にcell3,cell5を代入すると、print_list(y)で=>1=>5=>2=>3=>9が出力された.
   *引数にcell3,cell4を代入すると、4250656,1が出力された。
   *引数にcell3,cell4を代入すると、print_list(y)で=>1=>5=>2=>9が出力された。
   以上より、リストは連結され、また、戻り値として連結されたリストの先頭のセルへのポインタが返されていることが確認できた。
*/
struct cell*append(struct cell*list1,struct cell*list2)
{
	return concat(copy(list1),list2);
}
/*
　↓テスト(mainに残っているのはpart2)
----part1-------------------------------------------------------------------------------------
    *一つ目のリストをcreate_cellで作成.
		cell1はdataが2,nextが0の構造体のセルを指すポインタ
		cell2はdataが5,nextがcell1の構造体のセルを指すポインタ
		cell3はdataが1,nextがcell2の構造体のセルを指すポインタ
    *二つ目のリストをcreate_cellで作成
		cell4はdataが9,nextが0の構造体のセルを指すポインタ
    *二つのリストをconcatで結合し、
		 print_listで結合したリストを表示すると=>1=>5=>2=>9が出力された。
----part2-------------------------------------------------------------------------------------
　　*一つ目のリストをcreate_cellで作成.
		cell1はdataが2,nextが0の構造体のセルを指すポインタ
		cell2はdataが5,nextがcell1の構造体のセルを指すポインタ
		cell3はdataが1,nextがcell2の構造体のセルを指すポインタ
    *二つ目のリストをcreate_cellで作成
		cell4はdataが9,nextが0の構造体のセルを指すポインタ
		cell5はdataが3,nextがcell4の構造体のセルを指すポインタ
    *二つのリストをconcatで結合し、
		 print_listで結合したリストを表示すると=>1=>5=>2=>3=>9が出力された。
		以上より、セルを生成して二つのリストを作り、リストを結合して、
		結合されたリストを表示することが確認できた。
*/
int main()
{
	struct cell*cell1,*cell2,*cell3,*cell4,*cell5;
	//一つ目のリストを作成
	cell1 = create_cell(2, 0);
	cell2 = create_cell(5, cell1);
	cell3 = create_cell(1, cell2);
	//create_cellの確認
	//printf("%d,%d,%d",cell1,cell2,cell3);
	//print_list,create_cellの確認
	//print_list(cell3);

	//二つ目のリストを作成
	cell4 = create_cell(9,0);
	cell5 = create_cell(3,cell4);
	//リストを表示
	//print_list(cell5);

	//tail_listの確認
	//struct cell*z;
	//z=tail_list(cell3);
	//printf("%d,%d",z,z->data);
	
	//copyの確認
	struct cell*c1;
	c1=copy(cell3);
	//printf("%d,%d\n",c1,c1->data);
	
	//第1引数のリストが変更されないように二つのリストを連結
	struct cell*y;
	//y=concat(cell3,cell5);
	y=append(cell3,cell5);
	//printf("%d,%d\n",y,y->data);//戻り値の確認
	print_list(y);//連結されたリストを表示
	return 0;
}