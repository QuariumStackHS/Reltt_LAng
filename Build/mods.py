import os
def convert_bytes(num):
	for x in ['bytes', 'KB', 'MB', 'GB', 'TB']:
		if num < 1024.0:
			return "%3.1f %s" % (num, x)
		num /= 1024.0
def file_size(file_path):
	if os.path.isfile(file_path):
		file_info = os.stat(file_path)
		return convert_bytes(file_info.st_size)

class mod:
	def __init__(self,name,Path,size):
		self.name=name
		self.Path=Path
		self.size=file_size(Path)
		self.isused=1;
Mods=[mod("ASM","/Users/christopherclement/Projects/Reltt_LAng/Reltt/cache/ASM.o",'None',),mod("Compilator","/Users/christopherclement/Projects/Reltt_LAng/Reltt/cache/Compilator.o",'None',),mod("CPP_Module","/Users/christopherclement/Projects/Reltt_LAng/Reltt/cache/CPP_Module.o",'None',),mod("Generator","/Users/christopherclement/Projects/Reltt_LAng/Reltt/cache/Generator.o",'None',),mod("RelttSTD","/Users/christopherclement/Projects/Reltt_LAng/Reltt/cache/RelttSTD.o",'None',),mod("FSys","/Users/christopherclement/Projects/Reltt_LAng/Reltt/cache/FSys.o",'None',),mod("Remote","/Users/christopherclement/Projects/Reltt_LAng/Reltt/cache/Remote.o",'None',),mod("Qemu_D","/Users/christopherclement/Projects/Reltt_LAng/Reltt/cache/Qemu_D.o",'None',),]
