#directories
SOURCEDIR := src
LIBDIR := libs
BUILDDIR := build

#variables
APPNAME := main.exe
DEBUG := -g
FLAGS := -Wall -Wl,-subsystem,console
LIBS := -Iglad/include -ISDL/include -LSDL/lib -lmingw32 -lSDL2main -lSDL2
ARGS :=
ECHO := @
PROGRESS := 1


#find all folders in $(SOURCEDIR)
SOURCEFOLDERS := $(shell find $(SOURCEDIR) -type d)
#replace $(SOURCEDIR) to $(BUILDDIR) to understand what build folders we need to have
BUILDFOLDERS := $(foreach folder,$(SOURCEFOLDERS),$(subst $(SOURCEDIR),$(BUILDDIR),$(folder)))
#create all necesarily folders
$(foreach folder,$(BUILDFOLDERS),$(shell mkdir -p $(folder)))

#get all files we need to compile/link/include
SOURCES := $(foreach folder,$(SOURCEFOLDERS),$(wildcard $(folder)/*.cpp))
INCLUDES := $(foreach folder,$(SOURCEFOLDERS),$(addprefix -I,$(folder)))
INCLUDEFILES := $(foreach folder,$(SOURCEFOLDERS),$(wildcard $(folder)/*.hpp))
OBJS := $(foreach file,$(SOURCES),$(file:$(SOURCEDIR)/%.cpp:=$(BUILDDIR)/%.o))
#preprocess $(LIBS) to right format
LIBS := $(subst -I,-I$(LIBDIR)/,$(LIBS))
LIBS := $(subst -L,-L$(LIBDIR)/,$(LIBS))

run: compile
	$(ECHO)if [ $(PROGRESS) ]; then \
    echo Run!; \
  fi; \
	$(BUILDDIR)/$(APPNAME) $(ARGS)

runDebug: compile
	gdb --args $(BUILDDIR)/$(APPNAME) $(ARGS)

compile: $(OBJS)
	$(ECHO)g++ $(DEBUG) $(THIRD_PARTY) $(OBJS) -o $(BUILDDIR)/$(APPNAME) $(INCLUDES) $(FLAGS) $(LIBS); \
	if [ $(PROGRESS) ]; then \
    echo Compiled!; \
  fi

define generateRules
$(1:$(SOURCEDIR)/%.cpp:=$(BUILDDIR)/%.o): $1 $(INCLUDEFILES)
	$(ECHO)if [ $(PROGRESS) ]; then \
    echo Compiling $(notdir $(1))...; \
  fi; \
	g++ $(DEBUG) -c $$< -o $$@ $(INCLUDES) $(FLAGS) $(LIBS)

endef

$(foreach src,$(SOURCES),$(eval $(call generateRules,$(src))))

clean:
	$(ECHO)rm -r -f $(BUILDDIR)