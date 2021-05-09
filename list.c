/*2020/06/23*/
/*�Z���𐶐����ē�̃��X�g�����A��1�����̃��X�g���ύX����Ȃ��悤�Ƀ��X�g�̘A�������ĘA�����ꂽ���X�g��\������v���O����*/
#include<stdio.h>
struct cell {
	int data;
	struct cell *next;
};
struct cell cell_pool[1000];
struct cell*new_cell=&cell_pool[0];;
/*�Z���𐶐�����֐�
 *������data��next
 *�߂�l�͍\����cell���w���|�C���^
���e�X�g:main�ɖ߂�l��cell1,cell2,cell3�Ƃ��ĕ\���������B
	�܂��Aprint_list�Ń��X�g��\���������B
 *������data��next��������ƁAcell1,cell2,cell3�Ƃ���4250528,4250536,4250544���o�͂��ꂽ�B
 *print_list�̈�����cell3��������ƁA=>1=>5=>2���o�͂��ꂽ�B
�@�ȏ���A�Z���𐶐����āA���̃Z�����w���|�C���^��Ԃ��Ă��邱�Ƃ��m�F�ł����B
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
/*�J��Ԃ��ɂ���ă��X�g�����ǂ��āC�e�Z����data�����o�[��\������֐�
 *�����͍\���̂��w���|�C���^
 *�߂�l�͂Ȃ�
���e�X�g:main�Ŋ֐����Ăяo���A�\��������.
   *������cell1��������ƁA=>2���o�͂��ꂽ.
   *������cell2��������ƁA=>5=>2���o�͂��ꂽ.
   *������cell3��������ƁA=>1=>5=>2���o�͂��ꂽ.
   �ȏ���A���X�g�̂��J��Ԃ����ǂ�A�e�Z����data�����o�[��\�����邱�Ƃ��m�F�ł����B
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

/*���X�g�̏I���̃Z����T���ċA�֐�
 *�����̓��X�g�̍ŏ��̃Z���ւ̃|�C���^
 *�߂�l�͌��������Z���ւ̃|�C���^
 ���e�X�g:main�ɖ߂�l��z�Ƃ��ĕ\��������.�܂��A�߂�l�̃|�C���^���w���Z���̃f�[�^��\���������B
   *������cell3��������ƁA4250528,2���o�͂��ꂽ.
   *������cell4��������ƁA4250552,9���o�͂��ꂽ�B
   �ȏ���A���X�g�̏I���̃Z�����������T���Ă��邱�Ƃ��m�F�ł���.
*/
struct cell* tail_list(struct cell*p)
{
	if(p->next==0)return p;
	else return tail_list(p->next);
}
/*��̃��X�g��A������֐�
 *�����͓�̃��X�g�̂��ꂼ��̃Z���ւ̓�̃|�C���^
 *�߂�l�͘A�����ꂽ���X�g�̐擪�̃Z���ւ̃|�C���^
 ���e�X�g:main�Ɋ֐����Ăяo���A�߂�l��y�Ƃ��ĕ\���������B
�@ �܂��A�߂�l�̃|�C���^���w���Z���̃f�[�^��\���������B
   ����ɁAprint_list�Ŋm�F����.
   *������cell3,cell5��������ƁA4250544,1���o�͂��ꂽ.
   *������cell3,cell5��������ƁAprint_list(y)��=>1=>5=>2=>3=>9���o�͂��ꂽ.
   *������cell3,cell4��������ƁA4250544,1���o�͂��ꂽ�B
   *������cell3,cell4��������ƁAprint_list(y)��=>1=>5=>2=>9���o�͂��ꂽ�B
   �ȏ���A���X�g�͘A������A�܂��A�߂�l�Ƃ��ĘA�����ꂽ���X�g�̐擪�̃Z���ւ̃|�C���^���Ԃ���Ă��邱�Ƃ��m�F�ł����B
*/
struct cell*concat(struct cell*list1,struct cell*list2)
{
	struct cell*l;
	l=tail_list(list1);
	l->next=list2;
	
	return list1;
}
/*���郊�X�g�������ɗ^����ꂽ�Ƃ��ɁC������R�s�[����֐�
 *�����̓��X�g�̃Z�����w���|�C���^
 *�߂�l�̓��X�g�̃Z�����w���|�C���^
���e�X�g:main�ɖ߂�l��c1�Ƃ��ĕ\��������.�܂��A�߂�l�̃|�C���^���w���Z���̃f�[�^��\���������B
   *������cell3��������ƁA4250640,1���o�͂��ꂽ�B
�ȏ���A���郊�X�g�������ɗ^����ꂽ�Ƃ��ɁC������R�s�[���邱�Ƃ��m�F�ł����B
*/
struct cell*copy(struct cell*c)
{
	if(c->next==0)return c;
	else return create_cell(c->data,copy(c->next));
}
/*��1�����̃��X�g���ύX����Ȃ��悤�ɘA��������֐�
 *�����͓�̃��X�g�̂��ꂼ��̃Z���ւ̓�̃|�C���^
 *�߂�l�͂Ȃ�
 ���e�X�g:main�Ɋ֐����Ăяo���A�߂�l��y�Ƃ��ĕ\���������B
�@ �܂��A�߂�l�̃|�C���^���w���Z���̃f�[�^��\���������B
   ����ɁAprint_list�Ŋm�F����.
   *������cell3,cell5��������ƁA4250656,1���o�͂��ꂽ.
   *������cell3,cell5��������ƁAprint_list(y)��=>1=>5=>2=>3=>9���o�͂��ꂽ.
   *������cell3,cell4��������ƁA4250656,1���o�͂��ꂽ�B
   *������cell3,cell4��������ƁAprint_list(y)��=>1=>5=>2=>9���o�͂��ꂽ�B
   �ȏ���A���X�g�͘A������A�܂��A�߂�l�Ƃ��ĘA�����ꂽ���X�g�̐擪�̃Z���ւ̃|�C���^���Ԃ���Ă��邱�Ƃ��m�F�ł����B
*/
struct cell*append(struct cell*list1,struct cell*list2)
{
	return concat(copy(list1),list2);
}
/*
�@���e�X�g(main�Ɏc���Ă���̂�part2)
----part1-------------------------------------------------------------------------------------
    *��ڂ̃��X�g��create_cell�ō쐬.
		cell1��data��2,next��0�̍\���̂̃Z�����w���|�C���^
		cell2��data��5,next��cell1�̍\���̂̃Z�����w���|�C���^
		cell3��data��1,next��cell2�̍\���̂̃Z�����w���|�C���^
    *��ڂ̃��X�g��create_cell�ō쐬
		cell4��data��9,next��0�̍\���̂̃Z�����w���|�C���^
    *��̃��X�g��concat�Ō������A
		 print_list�Ō����������X�g��\�������=>1=>5=>2=>9���o�͂��ꂽ�B
----part2-------------------------------------------------------------------------------------
�@�@*��ڂ̃��X�g��create_cell�ō쐬.
		cell1��data��2,next��0�̍\���̂̃Z�����w���|�C���^
		cell2��data��5,next��cell1�̍\���̂̃Z�����w���|�C���^
		cell3��data��1,next��cell2�̍\���̂̃Z�����w���|�C���^
    *��ڂ̃��X�g��create_cell�ō쐬
		cell4��data��9,next��0�̍\���̂̃Z�����w���|�C���^
		cell5��data��3,next��cell4�̍\���̂̃Z�����w���|�C���^
    *��̃��X�g��concat�Ō������A
		 print_list�Ō����������X�g��\�������=>1=>5=>2=>3=>9���o�͂��ꂽ�B
		�ȏ���A�Z���𐶐����ē�̃��X�g�����A���X�g���������āA
		�������ꂽ���X�g��\�����邱�Ƃ��m�F�ł����B
*/
int main()
{
	struct cell*cell1,*cell2,*cell3,*cell4,*cell5;
	//��ڂ̃��X�g���쐬
	cell1 = create_cell(2, 0);
	cell2 = create_cell(5, cell1);
	cell3 = create_cell(1, cell2);
	//create_cell�̊m�F
	//printf("%d,%d,%d",cell1,cell2,cell3);
	//print_list,create_cell�̊m�F
	//print_list(cell3);

	//��ڂ̃��X�g���쐬
	cell4 = create_cell(9,0);
	cell5 = create_cell(3,cell4);
	//���X�g��\��
	//print_list(cell5);

	//tail_list�̊m�F
	//struct cell*z;
	//z=tail_list(cell3);
	//printf("%d,%d",z,z->data);
	
	//copy�̊m�F
	struct cell*c1;
	c1=copy(cell3);
	//printf("%d,%d\n",c1,c1->data);
	
	//��1�����̃��X�g���ύX����Ȃ��悤�ɓ�̃��X�g��A��
	struct cell*y;
	//y=concat(cell3,cell5);
	y=append(cell3,cell5);
	//printf("%d,%d\n",y,y->data);//�߂�l�̊m�F
	print_list(y);//�A�����ꂽ���X�g��\��
	return 0;
}