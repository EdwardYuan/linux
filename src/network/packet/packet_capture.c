/*

net-newbie.com/tcpip/packets.html

TCP Packet

"struct ether_header {}" + 
	"struct iphder {}" + 
		"data"

*/

/***********************************************
�\�P�b�g����

�\�P�b�g�f�B�X�N���v�^

�h���C���A�^�C�v�A�v���g�R���A�\�P�b�g�f�B�X�N���v�^�A�\�P�b�g�A�h���X�\����
AF_INET

PF_PACKET


************************************************/


/***********************************************
�V�X�e���R�[���{�\���́i�J�[�l���̋@�\���g�p����^�f�o�C�X���g�p����j

���t�@�C���f�B�X�N���v�^�ɑ΂��鑀��
�@�E�t�@�C���f�B�X�N���v�^���쐬����B
�@�E�t�@�C���f�B�X�N���v�^����ǂݍ��ށB
�@�E�t�@�C���f�B�X�N���v�^�ɏ������ށB
�@�E�t�@�C���f�B�X�N���v�^��j������B
�@�E�t�@�C���f�B�X�N���v�^�̑�����s���B�i���b�N�Ƃ��H�j
�@�E
�@�E
�@�E�\�P�b�g�A�h���X�\���́B
�@�E

���\�P�b�g�f�B�X�N���v�^�ɑ΂��鑀��
�@�E�ʐM�̂��߂�endpoint���쐬����B
�@�E�\�P�b�g�ɖ��O��t����B
�@�E�\�P�b�g�ɑ΂���ڑ����󂯕t����B
�@�E�\�P�b�g��̐ڑ���҂B
�@�E�\�P�b�g�̐ڑ����s���B
�@�E�\�P�b�g���烁�b�Z�[�W���󂯎��B
�@�E�\�P�b�g�f�B�X�N���v�^��j������B



���t�@�C���f�B�X�N���v�^�ɑ΂���C�x���g��҂�
�@�E�t�@�C���f�B�X�N���v�^�ɑ΂���C�x���g��҂B
�@�@int poll(struct pollfd *fds, nfds_t nfds, int timeout);
�@�@pollfd { int fd; short events; short revents; };
�@�E
�@�E
�@�E
�@�@
�@�@
���v���Z�X�ɑ΂��鑀��
�@�E�q�v���Z�X���쐬����B
�@�E�p�C�v���쐬����B
�@�E�v���Z�X�̏�ԕω���҂B

���f�o�C�X�ɑ΂��鑀��
�@�E�f�o�C�X (device) �𐧌䂷��B
�@�E
�@�E
�@�E�l�b�g���[�N�f�o�C�X�\����
�@�EALSA�\����
�@�EVideo4Linux�\����
�@


������IO�̑��d��
�@�E���d�����ꂽI/O�̓������Ƃ�B


���V�O�i���ɑ΂��鑀��
�@�E�V�O�i���𑀍삷��B

************************************************/



/***********************************************
�X���b�h����



************************************************/

//////////////////////////////////////////////////////////////////////////////////////////


/***********************************************
�p�P�b�g�L���v�`��

1.RAW�\�P�b�g���擾����B���f�o�C�X����
2.RAW�\�P�b�g�Ƀf�[�^�i�p�P�b�g�j������Γǂݍ��ށB
3.�ǂݍ��񂾃p�P�b�g����͂���B���p�P�b�g��͏���
4.2�ɖ߂�B

************************************************/

/***********************************************
�u���b�W
�i�m�[�g�̖����ƗL���ł̂Q�_�Ԃ݂̂̃u���b�W�j

�|�[�����O
�v���O�����ŕ����̃t�@�C���f�B�X�N���v�^���Ď�����B
��ȏ�̃t�@�C���f�B�X�N���v�^��������I/O�����ready��ԂɂȂ�܂ő҂B
ready��ԂƂ́A�Ή�����I/O���삪��~�Ȃ��Ɏ��s�\�ȏ�ԂɂȂ邱�ƁB

1.RAW�\�P�b�g���擾����B�i�L���j���f�o�C�X����
2.RAW�\�P�b�g���擾����B�i�����j���f�o�C�X����
3.�J�[�l���̃p�P�b�g�]���@�\�𖳌��ɂ���B���f�o�C�X����
4.�H�V�O�i���𖳌������遨�f�o�C�X����
5.�|�[�����O�ŊĎ�����C�x���g�̐ݒ���s���B
6.�|�[�����O�ŊĎ�����B
7.�p�P�b�g��ǂݍ��ށB
8.�ʂ̃C���^�[�t�F�C�X�ɏ������ށB
9.6�ɖ߂�B

************************************************/

/***********************************************
���[�^
��

�C���^�[�l�b�g�z�X�g�A�h���X���A IPv4�\�L����l�b�g���[�N�o�C�g�I�[�_�֕ϊ�����B
�f�o�C�X�����擾����B���f�o�C�X����
1.RAW�\�P�b�g���擾����B�i�L���j���f�o�C�X����
�f�o�C�X�����擾����B���f�o�C�X����
2.RAW�\�P�b�g���擾����B�i�����j���f�o�C�X����
3.�J�[�l���̃p�P�b�g�]���@�\�𖳌��ɂ���B���f�o�C�X����
�X���b�h�����̊J�n
4.�H�V�O�i���𖳌������遨�f�o�C�X����

5.�|�[�����O�ŊĎ�����C�x���g�̐ݒ���s���B
6.�|�[�����O�ŊĎ�����B
7.�p�P�b�g��ǂݍ��ށB
8.�ʂ̃C���^�[�t�F�C�X�ɏ������ށB
9.6�ɖ߂�B


1.Thread���J�n����B


************************************************/


/***********************************************
�f�o�C�X����

���iRAW�j�\�P�b�g�f�B�X�N���v�^���쐬����B
�@�E�h���C���{�^�C�v�{�v���g�R������ARAW�\�P�b�g���쐬����B
�@�E�l�b�g���[�N�C���^�[�t�F�C�X������������B
�@�E�l�b�g���[�N�f�o�C�X������A�l�b�g���[�N�C���^�[�t�F�C�X�C���f�b�N�X���擾����B
�@�E�h���C���{�v���g�R���{�l�b�g���[�N�C���^�[�t�F�C�X�C���f�b�N�X����A�\�P�b�g�A�h���X�ݒ��ݒ肷��B
�@�ERAW�\�P�b�g�{�\�P�b�g�A�h���X���o�C���h����B
�@�E�v���~�X�L���X�g�t���O������A�v���~�X�L���X�g��ݒ肷��B�i�I�v�V�����j
�@�@�{�v���~�X�L���X�g�t���O������A�v���~�X�L���X�g���擾����B
�@�@�{�v���~�X�L���X�g�t���O����A�l�b�g���[�N�C���^�[�t�F�C�X��ݒ肷��B
�@�ERAW�\�P�b�g�f�B�X�N���v�^�����^�[������B

���J�[�l���̃p�P�b�g�]���@�\�𖳌��ɂ���B
�@�E�h/proc/sys/net/ipv4/ip_forward�h����A�t�@�C���f�B�X�N���v�^���擾����B
�@�E�t�@�C���f�B�X�N���v�^�{���������N�G�X�g����A�H�J�[�l����ݒ肷��B

���f�o�C�X�����擾����B�i�����񉻂��ĂˁI�j
�@�EDGRAM�\�P�b�g���쐬���h���C���A�^�C�v�A�v���g�R���B
�@�E�l�b�g���[�N�C���^�[�t�F�C�X�������B
�@�E�l�b�g���[�N�C���^�[�t�F�C�X���ݒ聩�l�b�g���[�N�f�o�C�X���B
�@�EMAC�A�h���X���擾�����N�G�X�g�ADGRAM�\�P�b�g�A�l�b�g���[�N�C���^�[�t�F�C�X�B
�@�E���j�L���X�g�A�h���X���擾�����N�G�X�g�ADGRAM�\�P�b�g�A�l�b�g���[�N�C���^�[�t�F�C�X�B
�@�E�T�u�l�b�g���擾�����N�G�X�g�ADGRAM�\�P�b�g�A�l�b�g���[�N�C���^�[�t�F�C�X�B
�@�E�l�b�g�}�X�N���擾���T�u�l�b�g�B
�@�E�f�o�C�X�������^�[������B
�@
************************************************/


/***********************************************
�O���[�o���ϐ��A�\���́A�֐�

************************************************/


/***********************************************
�p�P�b�g��͏���

���ǂݍ��񂾃p�P�b�g����͂���B
�@�EARP/IP/IPv6�p�P�b�g����́��C�[�T�l�b�g�p�P�b�g�w�b�_�B
�@�@�{ARP�p�P�b�g��񁩉�́�ARP�p�P�b�g�i�C�[�T�l�b�g�w�b�_�̃^�C�v��ARP�j�B
�@�@�{ICMP/TCP/UDP�p�P�b�g����́�IP�p�P�b�g�i�C�[�T�l�b�g�w�b�_�̃^�C�v��IP�j�B
�@�@�@�|ICMP�p�P�b�g��񁩉�́�ICMP�p�P�b�g�iIP�w�b�_�̃v���g�R����ICMP�j�B
�@�@�@�|TCP�p�P�b�g��񁩉�́�TCP�p�P�b�g�iIP�w�b�_�̃v���g�R����TCP�j�B
�@�@�@�|UDP�p�P�b�g��񁩉�́�UDP�p�P�b�g�iIP�w�b�_�̃v���g�R����UDP�j�B
�@�@�{ICMP/TCP/UDP�p�P�b�g��IPv6�p�P�b�g�i�C�[�T�l�b�g�w�b�_�̃^�C�v��IPv6�j�B
�@�E�I���t���O�����^�[������B

�����ʉ�͏����B
�@�E�^�C�v��ʁ���́��p�P�b�g�w�b�_�B
�@�E�p�P�b�g���^�C�v�̃w�b�_�폜���p�P�b�g�w�b�_�B
�@�E�v���g�R����ʁ���́��p�P�b�g�w�b�_�B
�@�E�p�P�b�g��񁩉�́��p�P�b�g�B
�@�E�I���t���O�����^�[������B�i����\���^�ۑ�����j
�@
************************************************/


/***********************************************
�\���i�R�}���h���C���A�t�@�C���j

************************************************/


#include <stdio.h>
#include <string.h>
#include <unistd.h>

#include <sys/ioctl.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <linux/if.h>

#include <net/ethernet.h>
#include <netpacket/packet.h>
#include <netinet/if_ether.h>
#include <netinet/ip.h>

#include <netinet/ip6.h>
#include <netinet/ip_icmp.h>
#include <netinet/tcp.h>
#include <netinet/udp.h>

#include "netutils.h"
#include "analyze.h"


/*
 * 
 * 
 * "Domain" 		= PF_PACKET
 * 		"Socket Address" = struct sockaddr_ll
 * "Type" 		= SOCK_RAW
 * "Protocol" 	= ETH_P_IP, ETH_P_ALL
 * "Interface" 
 * "Promiss Cast" = NO, OFF
 *
 */



int main() {

	int sockfd;
	int size;
	u_char buf[65535];

	if((sockfd=init_raw_socket("eth1")) == -1) {
		debug_printf("error init %d %d\n", sockfd, sockfd);
		return(-1);
	}

/*	get_ether_info() {
	}*/
	
	while (1) {
		if((size=read(sockfd, buf, sizeof(buf))) <= 0) perror("read()");		
		analyze_packet(buf, size);
	}

	close(sockfd);
	return(0);

}

