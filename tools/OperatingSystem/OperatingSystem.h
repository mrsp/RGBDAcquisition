/** @file OperatingSystem.h
 *  @brief This is a small static library to connect RGBDAcquisition to the various file system conventions used by the various
 *  operating systems that exist , for now ( and the forseeable future ) it only addresses linux.
 *  That beeing said anything that has a different implementation for windows/linux and has to do with framework/API calls etc should go here
 *
 *  @author Ammar Qammaz (AmmarkoV)
 *  @bug OperatingSystem.h is supposed to provide cross platform basic functionality but for now it only supports Linux
 */


#ifndef OPERATINGSYSTEM_H_INCLUDED
#define OPERATINGSYSTEM_H_INCLUDED



#ifdef __cplusplus
extern "C"
{
#endif


/**
 * @brief This disects a string that contains a comma seperated list of directory files ( typically generated by the listDirectory call )
 * @ingroup misc
 * @param itemNum , Which comma seperated value to return
 * @param directoryList , Input string of comma seperated values which we want to parse
 * @param output , Where to store the specific string we got back with itemNum
 * @param maxOutput , The maximum size of output ( how many characters it can accomodate )
 * @retval 1=Success , 0=Failure
 */
int copyDirectoryListItem(int itemNum , char * directoryList , char * output, unsigned int maxOutput);



/**
 * @brief This returns a comma seperated string with all the files in directory
 * @ingroup misc
 * @param directory , The input directory to list
 * @param output , Where to store the comma seperated string that lists all files of directory
 * @param maxOutput , The maximum size of output ( how many characters it can accomodate )
 * @retval 1=Success , 0=Failure
 */
int listDirectory(char * directory , char * output, unsigned int maxOutput);


/**
 * @brief Register a function to receive CTRL+C etc kill requests so our clients will be able to exit gracefully on such events without leaving USB devices on etc
 * @ingroup misc
 * @param Pointer to a void  * function ( void )  that will be called on a kill event
 * @retval 1=Success , 0=Failure
 * @bug This only works on Linux
 */
int registerTerminationSignal(void * callback);

#ifdef __cplusplus
}
#endif


#endif // OPERATINGSYSTEMG_H_INCLUDED
