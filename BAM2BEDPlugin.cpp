#include "PluginManager.h"
#include <stdio.h>
#include <stdlib.h>
#include "BAM2BEDPlugin.h"

void BAM2BEDPlugin::input(std::string file) {
 inputfile = file;
}

void BAM2BEDPlugin::run() {}

void BAM2BEDPlugin::output(std::string file) {
 std::string outputfile = file;
myCommand += "bamToBed -i";
myCommand += " ";
myCommand += inputfile + " >& "+ outputfile;
 system(myCommand.c_str());
}

PluginProxy<BAM2BEDPlugin> BAM2BEDPluginProxy = PluginProxy<BAM2BEDPlugin>("BAM2BED", PluginManager::getInstance());
