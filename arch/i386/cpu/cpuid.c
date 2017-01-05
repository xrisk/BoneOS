/**
 ** This file is part of BoneOS.
 **
 **   BoneOS is free software: you can redistribute it and/or modify
 **   it under the terms of the GNU General Public License as published by
 **   the Free Software Foundation, either version 3 of the License, or
 **   (at your option) any later version.

 **   BoneOS is distributed in the hope that it will be useful,
 **   but WITHOUT ANY WARRANTY; without even the implied warranty of
 **   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 **   GNU General Public License for more details.

 **   You should have received a copy of the GNU General Public License
 **   along with BoneOS.  If not, see <http://www.gnu.org/licenses/>.
 **
 **  @main_author : Amanuel Bogale
 **  
 **  @contributors:

 **     Amanuel Bogale <amanuel2> : start
 **/ 

#include <cpu/cpuid.h>


/**
 * checks if the cpuid instruction is available
 * returns true if available
 */
bool has_cpuid_ins(){
	int res;
	__asm__ __volatile__ (".intel_syntax\n\t"
	                      "pushfd\n\t"
	                      "pushfd\n\t"
	                      "xor dword ptr [%%esp],0x200000\n\t"
	                      "popfd\n\t"
	                      "pushfd\n\t"
	                      "pop %%eax\n\t"
	                      "xor %%eax,[%%esp]\n\t"
	                      "popfd\n\t"
	                      "and %%eax,0x200000\n\t"
	                      ".att_syntax"
	                      :"=a"(res));
	return res;
}
