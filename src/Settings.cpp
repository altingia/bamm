/*
 *  settings.cpp
 *  rateshiftcombined
 *
 *  Created by Dan Rabosky on 2/6/12.
 *
*/


#include <iostream>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <cctype>
#include <algorithm>

#include "Settings.h"


/*
    Should rewrite this to NOT initialize any variables - just set to 0.

 */

Settings::Settings(void)
{

    _allParametersSetToDefaults = false;
    // Parameters used in main()
    _treefile = "EMPTY_STRING";
    _sampleProbsFilename = "EMPTY_STRING";
    _eventDataInfile = "EMPTY_STRING";
    _modeltype = "EMPTY_STRING";
    
    _runTraitModel = false;
    _runSpeciationExtinctionModel = false;
    _sampleFromPriorOnly = false;
    _runMCMC = false;
    _initializeModel = false;
    _loadEventData = false;
	_autotune = false;
	
    _useGlobalSamplingProbability = true;
    _globalSamplingFraction = 0.0;
	
    // Class Model parameters:
    _updateLambdaInitScale = 0.0;
    _updateMuInitScale = 0.0;
    _updateLambdaShiftScale = 0.0;
    _updateMuShiftScale = 0.0;
    _lambdaInit0 = 0.0;
    _lambdaShift0 = 0.0;
    _muInit0 = 0.0;
    _muShift0 = 0.0;
    _updateEventRateScale = 0.0;
    _localGlobalMoveRatio = 0.0;
    _targetNumber = 0.0;
    _lambdaInitPrior = 0.0;
    _lambdaShiftPrior = 0.0;
    _muInitPrior = 0.0;
    _muShiftPrior = 1.0;  // This is only set for convenience for now:
    
	_updateEventLocationScale = 0.0;
	//_MeanSpeciationLengthFraction = 0.0;
    
	
	_segLength = 0.0;

    _minCladeSizeForShift = 1;
    
    _seed = -1;

    // Parameters for implementation of class MCMC:
    _mcmcOutfile            =       "BAMM_mcmc_out.txt";
    _eventDataOutfile       =       "BAMM_eventdata.txt";
    _lambdaOutfile          =       "BAMM_lambda_rates.txt";
    _muOutfile              =       "BAMM_mu_rates.txt";
    _acceptrateOutfile      =       "BAMM_mcmc_accept.txt";
    _lambdaNodeOutfile      =       "BAMM_nodeLambda.txt";

    _treeWriteFreq          =       0;
    _eventDataWriteFreq     =       0;
    _mcmcWriteFreq          =       0;
    _acceptWriteFreq        =       0;
    _printFreq              =       0;
    _NGENS                  =       0;

    _updateRateEventNumber                  =   0.0;
    _updateRateEventPosition                =   0.0;
    _updateRateEventRate                    =   0.0;
    _updateRateLambda0                      =   0.0;
    _updateRateLambdaShift                  =   0.0;
    _updateRateMu0                          =   0.0;
    _updateRateMuShift                      =   0.0;
    _updateRateNumberTimeVariablePartitions =   0.0;

    // Other:
    _initialNumberEvents                    =   0;

    /*******************************************/
    // Set Boolean indicator variables to track
    //   changes to default parameters:
    isDefault_modeltype                                    = true;
    isDefault_treefile                                  = true;
    isDefault_runTraitModel                             = true;
    isDefault_runSpeciationExtinctionModel              = true;
    isDefault_sampleFromPriorOnly                       = true;
    isDefault_runMCMC                                   = true;
    isDefault_initializeModel                           = true;
    isDefault_loadEventData                             = true;
    isDefault_useGlobalSamplingProbability              = true;
    isDefault_sampleProbsFilename                       = true;
    isDefault_globalSamplingFraction                    = true;
    isDefault_updateLambdaInitScale                     = true;
    isDefault_updateMuInitScale                         = true;
    isDefault_updateLambdaShiftScale                    = true;
    isDefault_updateMuShiftScale                        = true;
    isDefault_lambdaInit0                               = true;
    isDefault_lambdaShift0                              = true;
    isDefault_muInit0                                   = true;
    isDefault_muShift0                                  = true;
    isDefault_updateEventRateScale                      = true;
    isDefault_localGlobalMoveRatio                      = true;
    isDefault_targetNumber                              = true;
    isDefault_lambdaInitPrior                           = true;
    isDefault_lambdaShiftPrior                          = true;
    isDefault_muInitPrior                               = true;
    isDefault_muShiftPrior                              = true;
    isDefault_updateEventLocationScale					= true;
	//isDefault_MeanSpeciationLengthFraction              = true;
    
	isDefault_segLength                                 = true;
    isDefault_mcmcOutfile                               = true;
    isDefault_eventDataOutfile                          = true;
    isDefault_lambdaOutfile                             = true;
    isDefault_muOutfile                                 = true;
    isDefault_acceptrateOutfile                         = true;
    isDefault_lambdaNodeOutfile                         = true;
    isDefault_treeWriteFreq                             = true;
    isDefault_eventDataWriteFreq                        = true;
    isDefault_mcmcWriteFreq                             = true;
    isDefault_acceptWriteFreq                           = true;
    isDefault_printFreq                                 = true;
    isDefault_NGENS                                     = true;
    isDefault_updateRateEventNumber                     = true;
    isDefault_updateRateEventPosition                   = true;
    isDefault_updateRateEventRate                       = true;
    isDefault_updateRateLambda0                         = true;
    isDefault_updateRateLambdaShift                     = true;
    isDefault_updateRateMu0                             = true;
    isDefault_updateRateMuShift                         = true;
    isDefault_updateRateNumberTimeVariablePartitions    = true;
    isDefault_initialNumberEvents                       = true;

    isDefault_eventDataInfile                           = true;
    isDefault_minCladeSizeForShift                      = true;
    isDefault_seed                                      = true;

	isDefault_autotune									= true;
	
    // End block of Booleans
    /*******************************************/

    /* Trait evolution module parameters  */
    _traitfile                  =   "EMPTY";
    _updateBetaScale            =   0.0;
    _updateNodeStateScale       =   0.0;
    _updateBetaShiftScale       =   0.0;

    _betaInit                   =   0.0;
    _betaShiftInit              =   0.0;

    _rootPrior                  =   0.0;
    _betaInitPrior              =   0.0;
    _betaShiftPrior             =   0.0;

    _traitPriorMin              =   0.0;
    _traitPriorMax              =   0.0;

    isDefault_traitfile         = true;
    isDefault_updateBetaScale   = true;
    isDefault_updateNodeStateScale = true;
    isDefault_betaInit          = true;
    isDefault_rootPrior         = true;
    isDefault_traitPriorMin     = true;
    isDefault_traitPriorMax     = true;
    isDefault_useObservedMinMaxAsTraitPriors = true;
    isDefault_betaOutfile       = true;
    isDefault_nodeStateOutfile  = true;

    isDefault_updateRateBetaShift   = true;
    isDefault_updateRateBeta0       = true;
    isDefault_updateRateNodeState   = true;

    _useObservedMinMaxAsTraitPriors = true;

    _betaOutfile        =   "BAMM_beta_rates.txt";
    _nodeStateOutfile   =   "BAMM_nodestates.txt";

}


Settings::~Settings(void)
{


}


void Settings::initializeSettingsDevel(std::string controlFilename)
{
    std::ifstream infile(controlFilename.c_str());
    if (!infile.good()) {
        std::cout << "Control filename invalid" << std::endl;
        std::cout << "Exiting." << std::endl;
        throw;
    }
    
    std::cout << "Reading control file <<" << controlFilename.c_str() << ">>" << std::endl;
	
    std::string s1, s2, s_nocomment;
    
    while (infile) {
        getline(infile, s1, '\n');
        
        // strip whitespace out of tempstring:
        //      both spaces and tabs:
        
        // What is the int(*)(int) doing????
        s1.erase(std::remove_if(s1.begin(), s1.end(), (int(*)(int))isspace), s1.end());
		
		
		std::istringstream sx(s1);       
		getline(sx, s_nocomment, '#');
		
		// Only add if has size > 0 (gets rid of empty lines)
        if (s_nocomment.size() > 0) {
            std::vector<std::string> tmpstr;
            
            // NOw use second getline to split by '=' characters:

            std::istringstream stemp(s_nocomment);

            while (getline(stemp, s2, '=')){
                tmpstr.push_back(s2);        
            }

            if (tmpstr.size() == 2) {
                _varName.push_back(tmpstr[0]);
                _varValue.push_back(tmpstr[1]);
            } else{
                std::cout << "Invalid size of input line in control file" << std::endl;
				std::cout << " Problematic line includes <<" << s_nocomment << ">>" << std::endl;
				std::cout << "Terminating run\n" << std::endl;
				exit(0);			
			}

		}
        
        if (infile.peek() == EOF)
            break;
    }
    
    for (std::vector<std::string>::size_type i = 0; i < _varName.size(); i++){
        //std::cout << _varName[i] << std::endl;
        if (_varName[i] == "modeltype") {
            _modeltype = _varValue[i];
            isDefault_modeltype = false;
        }
    }
    
    if (_modeltype == "EMPTY_STRING") {
        std::cout << "Invalid type of analysis" << std::endl;
        std::cout << "Options: speciationextinction or trait" << std::endl;
        throw;    
    } else if (_modeltype == "speciationextinction") {
        initializeSettings_Diversification();
    } else if (_modeltype == "trait") {
        initializeSettings_Traits();
    } else {
    
        throw;
    }
    
}


/*
    Initializes all settings directly in the compiled code.


 */

void Settings::initializeSettingsDefaults_Diversification(void)
{

    _allParametersSetToDefaults = true;

    _runSpeciationExtinctionModel   = true;
    _runTraitModel                  = false;

    // Parameters used in main()
    _treefile = "test_tree.tre";

    _sampleFromPriorOnly = false;
    _runMCMC = true;
    _initializeModel = true;

    _useGlobalSamplingProbability   = true;
    _sampleProbsFilename = "skinksprobs.txt";

    _globalSamplingFraction         = 0.95;

    // Class Model parameters:
    _updateLambdaInitScale          = 2.0;
    _updateMuInitScale              = 2.0;
    _updateLambdaShiftScale         = 2.0;
    _updateMuShiftScale             = 0.0; // 0
    _lambdaInit0                    = 1.0;
    _lambdaShift0                   = 0.0;
    _muInit0                        = 0.1;
    _muShift0                       = 0.0;
    _updateEventRateScale           = 4.0;
    _localGlobalMoveRatio           = 10.0;
    _targetNumber                   = 1.0;
    _lambdaInitPrior                = 1.0;
    _lambdaShiftPrior               = 0.5;
    _muInitPrior                    = 1.0;
    _muShiftPrior                   = 0.5; // 0
    //_MeanSpeciationLengthFraction   = 0.2;
    _updateEventLocationScale		= 1.0;
	_segLength                      = 1.0;

    _minCladeSizeForShift           = 1;

    // Parameters for implementation of class MCMC:
    _mcmcOutfile            =       "mcmc_out.txt";
    _eventDataOutfile       =       "eventdata.txt";
    _eventDataInfile        =       "EMPTY_STRING";
    _lambdaOutfile          =       "lambda_rates.txt";
    _muOutfile              =       "mu_rates.txt";
    _acceptrateOutfile      =       "mcmc_accept.txt";
    _lambdaNodeOutfile      =       "nodeLambda.txt";


    _treeWriteFreq          =       5000;
    _eventDataWriteFreq     =       5000;
    _mcmcWriteFreq          =       1000;
    _acceptWriteFreq        =       1000;
    _printFreq              =       1000;
    _NGENS                  =       2000000;

    _updateRateEventNumber      =   1.0;
    _updateRateEventPosition    =   1.0;
    _updateRateEventRate        =   1.0;
    _updateRateLambda0          =   10.0;
    _updateRateLambdaShift      =   10.0;
    _updateRateMu0              =   10.0;
    _updateRateMuShift          =   0.0; // 0.0

    _updateRateNumberTimeVariablePartitions = 0.0;

    // Other:
    _initialNumberEvents = 0;


}

void Settings::initializeSettingsDefaults_Traits(void)
{
    _allParametersSetToDefaults = true;

    _runSpeciationExtinctionModel   = false;
    _runTraitModel                  = true;

    // Parameters used in main()
    _treefile = "test_tree.txt";
    _traitfile  = "morph.txt";

    _sampleFromPriorOnly = false;
    _runMCMC = true;
    _initializeModel = true;

    // Class Model parameters:
    _updateBetaScale                = 0.25;
    _updateNodeStateScale           = 0.25;
    _updateBetaShiftScale           = 0.25;

    _updateEventRateScale           = 2.0;
    _localGlobalMoveRatio           = 10.0;
    _targetNumber                   = 0.5;
//   _MeanSpeciationLengthFraction   = 0.2;
	_updateEventLocationScale		= 1.0;
    _betaInit           =   0.1;
    _betaShiftInit      =   0.0;

    _betaInitPrior      =   1.0;
    _betaShiftPrior     =   0.1;

    // These still have default values:
    _useObservedMinMaxAsTraitPriors = true;
    _traitPriorMin                  =   0.0;
    _traitPriorMax                  =   0.0;

    // Parameters for implementation of class MCMC:
    _mcmcOutfile            =       "BAMMt_mcmc_out.txt";
    _eventDataOutfile       =       "BAMMt_eventdata.txt";
    _betaOutfile            =       "BAMMt_beta_rates.txt";
    _nodeStateOutfile       =       "BAMMt_nodestates.txt";
    _acceptrateOutfile      =       "BAMMt_mcmc_accept.txt";

    _treeWriteFreq          =       50000;
    _eventDataWriteFreq     =       50000;
    _mcmcWriteFreq          =       1000;
    _acceptWriteFreq        =       1000;
    _printFreq              =       10000;
    _NGENS                  =       10000000;

    _updateRateEventNumber      =   1.0;
    _updateRateEventPosition    =   1.0;
    _updateRateEventRate        =   1.0;

    _updateRateBeta0            =   1.0;
    _updateRateNodeState        =   25.0;
    _updateRateBetaShift        =   1.0;

    _updateRateNumberTimeVariablePartitions = 0.0;

    // Other:
    _initialNumberEvents = 0;


}


void Settings::initializeSettings_Traits()
{



    _allParametersSetToDefaults = false;

    std::vector<std::string> paramsNotFound;




    for (std::vector<std::string>::size_type i = 0; i < _varName.size(); i++) {
        //std::cout << std::setw(30) << _varName[i] << std::setw(20) << _varValue[i] << std::endl;

        if (_varName[i] == "treefile") {
            _treefile = _varValue[i];
            isDefault_treefile = false;
        } else if (_varName[i] == "traitfile") {
            _traitfile = _varValue[i];
            isDefault_traitfile = false;
        } else if (_varName[i] == "runSpeciationExtinctionModel") {

        } else if (_varName[i] == "runTraitModel") {

        } else if (_varName[i] == "sampleFromPriorOnly") {
            _sampleFromPriorOnly = stringToBool(_varValue[i].c_str());

            isDefault_sampleFromPriorOnly = false;
        } else if (_varName[i] == "initializeModel") {
            _initializeModel = stringToBool(_varValue[i].c_str());
            isDefault_initializeModel = false;
        } else if (_varName[i] == "runMCMC") {
            _runMCMC = stringToBool(_varValue[i].c_str());
            isDefault_runMCMC = false;
        } else if (_varName[i] == "updateBetaScale") {
            _updateBetaScale = atof(_varValue[i].c_str());
            isDefault_updateBetaScale = false;
            //std::cout << left << std::setw(ppw) << "updateLambdaInitScale" << "\t" << _updateLambdaInitScale << std::endl;

        } else if (_varName[i] == "updateNodeStateScale") {
            _updateNodeStateScale = atof(_varValue[i].c_str());
            isDefault_updateNodeStateScale = false;
        } else if (_varName[i] == "updateBetaShiftScale") {
            _updateBetaShiftScale = atof(_varValue[i].c_str());
            isDefault_updateBetaShiftScale = false;
        } else if (_varName[i] == "betaInit") {
            _betaInit = atof(_varValue[i].c_str());
            isDefault_betaInit = false;
        } else if (_varName[i] == "betaShiftInit") {
            _betaShiftInit = atof(_varValue[i].c_str());
            isDefault_betaShift = false;
        } else if (_varName[i] == "updateEventLocationScale"){
			_updateEventLocationScale = atof(_varValue[i].c_str());
			isDefault_updateEventLocationScale = false;
		}else if (_varName[i] == "updateEventRateScale") {
            _updateEventRateScale = atof(_varValue[i].c_str());
            isDefault_updateEventRateScale = false;
        } else if (_varName[i] == "localGlobalMoveRatio") {
            _localGlobalMoveRatio = atof(_varValue[i].c_str());
            isDefault_localGlobalMoveRatio = false;
        } else if (_varName[i] == "targetNumber") {
            _targetNumber = atof(_varValue[i].c_str());
            isDefault_targetNumber = false;
        } else if (_varName[i] == "betaInitPrior") {
            _betaInitPrior = atof(_varValue[i].c_str());
            isDefault_betaInitPrior = false;
        } else if (_varName[i] == "betaShiftPrior") {
            _betaShiftPrior = atof(_varValue[i].c_str());
            isDefault_betaShiftPrior = false;
        } else if (_varName[i] == "useObservedMinMaxAsTraitPriors") {
            _useObservedMinMaxAsTraitPriors = stringToBool(_varValue[i].c_str());
            isDefault_useObservedMinMaxAsTraitPriors = false;
        } else if (_varName[i] == "traitPriorMin") {
            _traitPriorMin = atof(_varValue[i].c_str());
            isDefault_traitPriorMin = false;
        } else if (_varName[i] == "traitPriorMax") {
            _traitPriorMax = atof(_varValue[i].c_str());
            isDefault_traitPriorMax = false;
        } else if (_varName[i] == "mcmcOutfile") {
            _mcmcOutfile = _varValue[i];
            isDefault_mcmcOutfile = false;
        } else if (_varName[i] == "eventDataOutfile") {
            _eventDataOutfile = _varValue[i];
            isDefault_eventDataOutfile = false;
        } else if (_varName[i] == "betaOutfile") {
            _betaOutfile = _varValue[i];
            isDefault_betaOutfile = false;
        } else if (_varName[i] == "nodeStateOutfile") {
            _nodeStateOutfile = _varValue[i];
            isDefault_nodeStateOutfile = false;
        } else if (_varName[i] == "acceptrateOutfile") {
            _acceptrateOutfile = _varValue[i];
            isDefault_acceptrateOutfile = false;
        } else if (_varName[i] == "treeWriteFreq") {
            _treeWriteFreq = atoi(_varValue[i].c_str());
            isDefault_treeWriteFreq = false;
        } else if (_varName[i] == "eventDataWriteFreq") {
            _eventDataWriteFreq = atoi(_varValue[i].c_str());
            isDefault_eventDataWriteFreq = false;
        } else if (_varName[i] == "mcmcWriteFreq") {
            _mcmcWriteFreq = atoi(_varValue[i].c_str());
            isDefault_mcmcWriteFreq = false;
        } else if (_varName[i] == "acceptWriteFreq") {
            _acceptWriteFreq = atoi(_varValue[i].c_str());
            isDefault_acceptWriteFreq = false;
        } else if (_varName[i] == "printFreq") {
            _printFreq = atoi(_varValue[i].c_str());
            isDefault_printFreq = false;
        } else if (_varName[i] == "NumberGenerations") {
            _NGENS = atoi(_varValue[i].c_str());
            isDefault_NGENS = false;
        } else if (_varName[i] == "updateRateEventNumber") {
            _updateRateEventNumber  = atof(_varValue[i].c_str());
            isDefault_updateRateEventNumber = false;
        } else if (_varName[i] == "updateRateEventPosition") {
            _updateRateEventPosition  = atof(_varValue[i].c_str());
            isDefault_updateRateEventPosition = false;
        } else if (_varName[i] == "updateRateEventRate") {
            _updateRateEventRate = atof(_varValue[i].c_str());
            isDefault_updateRateEventRate = false;
        } else if (_varName[i] == "updateRateBeta0") {
            _updateRateBeta0 = atof(_varValue[i].c_str());
            isDefault_updateRateBeta0 = false;
        } else if (_varName[i] == "updateRateBetaShift") {
            _updateRateBetaShift  = atof(_varValue[i].c_str());
            isDefault_updateRateBetaShift = false;
        } else if (_varName[i] == "updateRateNodeState") {
            _updateRateNodeState = atoi(_varValue[i].c_str());
            isDefault_updateRateNodeState = false;
        } else if (_varName[i] == "initialNumberEvents") {
            _initialNumberEvents  = atoi(_varValue[i].c_str());
            isDefault_initialNumberEvents = false;
        } else if (_varName[i] == "loadEventData" ) {
            _loadEventData = stringToBool(_varValue[i].c_str());
            isDefault_loadEventData = false;
        } else if (_varName[i] == "eventDataInfile") {
            _eventDataInfile = _varValue[i].c_str();
            isDefault_eventDataInfile = false;
        } else if (_varName[i] == "modeltype"){
            // Do nothing. This is 
            // already handled in initializeSettings() general function.
        }else if (_varName[i] == "autotune"){
			_autotune = stringToBool(_varValue[i].c_str());
			isDefault_autotune = false;
		}else {
            // Parameter not found:
            //      add to list of potentially bad/misspelled params
            //      and print for user.
            paramsNotFound.push_back(_varName[i]);
        }

    }

    std::cout << "Read a total of <<" << _varName.size() <<
         ">> parameter settings from control file" << std::endl;
    if (paramsNotFound.size() > 0) {
        std::cout << std::endl << "********************************" << std::endl;
        std::cout << "BAMM error: one or more parameters from control file do not correspond"
             << std::endl;
        std::cout << "\tto valid model parameters.";
        std::cout << "Check the following to see if they are ";
        std::cout << "\tspecified (or spelled) correctly:" << std::endl << std::endl;
        for (std::vector<std::string>::size_type i = 0; i < paramsNotFound.size(); i++)
            std::cout << std::setw(30) << paramsNotFound[i] << std::endl;
        std::cout << std::endl << "********************************" << std::endl << std::endl;
        std::cout << "Execution of BAMM terminated..." << std::endl;
        exit(1);

    }

    //  Here we have a print block to output Settings:
    //  Any parameters NOT set will have the defaults.
    //  Thus user can specify a control file with ONLY
    //      those parameters that they wish to change
    //      from the defaults, eg inputfilename etc.

    //  Output list of default parameters.


}

void Settings::printCurrentSettings_Traits(bool printOnlyChangesToDefaults)
{
    std::cout << "print settings for trait module not yet supported" << std::endl;
    exit(1);
}

void Settings::initializeSettings_Diversification()
{

    _allParametersSetToDefaults = false;

    std::vector<std::string> paramsNotFound;
 

    for (std::vector<std::string>::size_type i = 0; i < _varName.size(); i++) {
        //std::cout << std::setw(30) << _varName[i] << std::setw(20) << _varValue[i] << std::endl;

        if (_varName[i] == "treefile") {
            _treefile = _varValue[i];
            isDefault_treefile = false;
        } else if (_varName[i] == "runSpeciationExtinctionModel") {

        } else if (_varName[i] == "runTraitModel") {

        } else if (_varName[i] == "sampleFromPriorOnly") {
            _sampleFromPriorOnly = stringToBool(_varValue[i].c_str());

            isDefault_sampleFromPriorOnly = false;
        } else if (_varName[i] == "initializeModel") {
            _initializeModel = stringToBool(_varValue[i].c_str());
            isDefault_initializeModel = false;
        } else if (_varName[i] == "runMCMC") {
            _runMCMC = stringToBool(_varValue[i].c_str());
            isDefault_runMCMC = false;
        } else if (_varName[i] == "useGlobalSamplingProbability") {
            _useGlobalSamplingProbability = stringToBool(_varValue[i].c_str());
            isDefault_useGlobalSamplingProbability = false;
        } else if (_varName[i] == "sampleProbsFilename") {
            _sampleProbsFilename = _varValue[i];
            isDefault_sampleProbsFilename = false;
            //std::cout << left << std::setw(ppw) << "sampleProbsFilename" << "\t" << _sampleProbsFilename << std::endl;

        } else if (_varName[i] == "globalSamplingFraction") {
            _globalSamplingFraction = atof(_varValue[i].c_str());
            isDefault_globalSamplingFraction = false;
            //std::cout << left << std::setw(ppw) << "globalSamplingFraction" << "\t" << _globalSamplingFraction << std::endl;

        } else if (_varName[i] == "updateLambdaInitScale") {
            _updateLambdaInitScale = atof(_varValue[i].c_str());
            isDefault_updateLambdaInitScale = false;
            //std::cout << left << std::setw(ppw) << "updateLambdaInitScale" << "\t" << _updateLambdaInitScale << std::endl;

        } else if (_varName[i] == "updateMuInitScale") {
            _updateMuInitScale = atof(_varValue[i].c_str());
            isDefault_updateMuInitScale = false;
        } else if (_varName[i] == "updateLambdaShiftScale") {
            _updateLambdaShiftScale = atof(_varValue[i].c_str());
            isDefault_updateLambdaShiftScale = false;
        } else if (_varName[i] == "updateMuShiftScale") {
            _updateMuShiftScale = atof(_varValue[i].c_str());
            isDefault_updateMuShiftScale = false;
        } else if (_varName[i] == "lambdaInit0") {
            _lambdaInit0 = atof(_varValue[i].c_str());
            isDefault_lambdaInit0 = false;
        } else if (_varName[i] == "lambdaShift0") {
            _lambdaShift0 = atof(_varValue[i].c_str());
            isDefault_lambdaShift0 = false;
        } else if (_varName[i] == "muInit0") {
            _muInit0 = atof(_varValue[i].c_str());
            isDefault_muInit0 = false;
        } else if (_varName[i] == "muShift0") {
            _muShift0 = atof(_varValue[i].c_str());
            isDefault_muShift0 = false;
        } else if (_varName[i] == "updateEventLocationScale") {
            _updateEventLocationScale = atof(_varValue[i].c_str());
            isDefault_updateEventLocationScale = false;
        } else if (_varName[i] == "updateEventRateScale") {
            _updateEventRateScale = atof(_varValue[i].c_str());
            isDefault_updateEventRateScale = false;
        } else if (_varName[i] == "localGlobalMoveRatio") {
            _localGlobalMoveRatio = atof(_varValue[i].c_str());
            isDefault_localGlobalMoveRatio = false;
        } else if (_varName[i] == "targetNumber") {
            _targetNumber = atof(_varValue[i].c_str());
            isDefault_targetNumber = false;
        } else if (_varName[i] == "lambdaInitPrior") {
            _lambdaInitPrior = atof(_varValue[i].c_str());
            isDefault_lambdaInitPrior = false;
        } else if (_varName[i] == "lambdaShiftPrior") {
            _lambdaShiftPrior = atof(_varValue[i].c_str());
            isDefault_lambdaShiftPrior = false;
        } else if (_varName[i] == "muInitPrior") {
            _muInitPrior = atof(_varValue[i].c_str());
            isDefault_muInitPrior = false;
        } else if (_varName[i] == "muShiftPrior") {
            _muShiftPrior = atof(_varValue[i].c_str());
            isDefault_muShiftPrior = false;
        } else if (_varName[i] == "segLength") {
            _segLength = atof(_varValue[i].c_str());
            isDefault_segLength = false;
        } else if (_varName[i] == "mcmcOutfile") {
            _mcmcOutfile = _varValue[i];
            isDefault_mcmcOutfile = false;
        } else if (_varName[i] == "eventDataOutfile") {
            _eventDataOutfile = _varValue[i];
            isDefault_eventDataOutfile = false;
        } else if (_varName[i] == "lambdaOutfile") {
            _lambdaOutfile = _varValue[i];
            isDefault_lambdaOutfile = false;
        } else if (_varName[i] == "muOutfile") {
            _muOutfile = _varValue[i];
            isDefault_muOutfile = false;
        } else if (_varName[i] == "acceptrateOutfile") {
            _acceptrateOutfile = _varValue[i];
            isDefault_acceptrateOutfile = false;
        } else if (_varName[i] == "lambdaNodeOutfile") {
            _lambdaNodeOutfile = _varValue[i];
            isDefault_lambdaNodeOutfile = false;
        } else if (_varName[i] == "treeWriteFreq") {
            _treeWriteFreq = atoi(_varValue[i].c_str());
            isDefault_treeWriteFreq = false;
        } else if (_varName[i] == "eventDataWriteFreq") {
            _eventDataWriteFreq = atoi(_varValue[i].c_str());
            isDefault_eventDataWriteFreq = false;
        } else if (_varName[i] == "mcmcWriteFreq") {
            _mcmcWriteFreq = atoi(_varValue[i].c_str());
            isDefault_mcmcWriteFreq = false;
        } else if (_varName[i] == "acceptWriteFreq") {
            _acceptWriteFreq = atoi(_varValue[i].c_str());
            isDefault_acceptWriteFreq = false;
        } else if (_varName[i] == "printFreq") {
            _printFreq = atoi(_varValue[i].c_str());
            isDefault_printFreq = false;
        } else if (_varName[i] == "NumberGenerations") {
            _NGENS = atoi(_varValue[i].c_str());
            isDefault_NGENS = false;
        } else if (_varName[i] == "updateRateEventNumber") {
            _updateRateEventNumber  = atof(_varValue[i].c_str());
            isDefault_updateRateEventNumber = false;
        } else if (_varName[i] == "updateRateEventPosition") {
            _updateRateEventPosition  = atof(_varValue[i].c_str());
            isDefault_updateRateEventPosition = false;
        } else if (_varName[i] == "updateRateEventRate") {
            _updateRateEventRate = atof(_varValue[i].c_str());
            isDefault_updateRateEventRate = false;
        } else if (_varName[i] == "updateRateLambda0") {
            _updateRateLambda0  = atof(_varValue[i].c_str());
            isDefault_updateRateLambda0 = false;
        } else if (_varName[i] == "updateRateLambdaShift") {
            _updateRateLambdaShift  = atof(_varValue[i].c_str());
            isDefault_updateRateLambdaShift = false;
        } else if (_varName[i] == "updateRateMu0") {
            _updateRateMu0  = atof(_varValue[i].c_str());
            isDefault_updateRateMu0 = false;
        } else if (_varName[i] == "updateRateMuShift") {
            _updateRateMuShift  = atof(_varValue[i].c_str());
            isDefault_updateRateMuShift = false;
        } else if (_varName[i] == "initialNumberEvents") {
            _initialNumberEvents  = atoi(_varValue[i].c_str());
            isDefault_initialNumberEvents = false;
        } else if (_varName[i] == "loadEventData" ) {
            _loadEventData = stringToBool(_varValue[i].c_str());
            isDefault_loadEventData = false;
        } else if (_varName[i] == "eventDataInfile") {
            _eventDataInfile = _varValue[i].c_str();
            isDefault_eventDataInfile = false;
        } else if (_varName[i] == "minCladeSizeForShift") {
            _minCladeSizeForShift = atoi(_varValue[i].c_str());
            isDefault_minCladeSizeForShift = false;
        } else if (_varName[i] == "modeltype"){
            // Do nothing. This is 
            // already handled in initializeSettings() general function.
        } else if (_varName[i] == "autotune"){
			_autotune = stringToBool(_varValue[i].c_str());
			isDefault_autotune = false;
		}else if (_varName[i] == "seed") {
            _seed = atoi(_varValue[i].c_str());
            isDefault_seed = false;
        } else {
            // Parameter not found:
            //      add to list of potentially bad/misspelled params
            //      and print for user.
            paramsNotFound.push_back(_varName[i]);
        }

    }

    std::cout << "Read a total of <<" << _varName.size() <<
         ">> parameter settings from control file" << std::endl;
    if (paramsNotFound.size() > 0) {
        std::cout << std::endl << "********************************" << std::endl;
        std::cout << "BAMM error: one or more parameters from control file do not correspond"
             << std::endl;
        std::cout << "\tto valid model parameters.";
        std::cout << "Check the following to see if they are ";
        std::cout << "\tspecified (or spelled) correctly:" << std::endl << std::endl;
        for (std::vector<std::string>::size_type i = 0; i < paramsNotFound.size(); i++) {
            std::cout << std::setw(30) << paramsNotFound[i] << std::endl;
        }
        std::cout << std::endl << "********************************" << std::endl << std::endl;
        std::cout << "Execution of BAMM terminated..." << std::endl;
        exit(1);
    }

    //  Here we have a print block to output Settings:
    //  Any parameters NOT set will have the defaults.
    //  Thus user can specify a control file with ONLY
    //      those parameters that they wish to change
    //      from the defaults, eg inputfilename etc.

    //  Output list of default parameters.

}


void Settings::checkAreInitialSettingsValid_Diversification(void)
{

    std::cout << "currently does not check for valid settings" << std::endl;
    std::cout << " in speciation-extinction BAMM" << std::endl << std::endl;
    std::cout << "This will be fixed in a future release of BAMM" << std::endl << std::endl;
}



void Settings::checkAreInitialSettingsValid_Traits(void)
{
    std::vector<std::string> paramsNotSpecified;

    if (isDefault_traitfile)
        paramsNotSpecified.push_back("traitfile");
    if (isDefault_treefile)
        paramsNotSpecified.push_back("treefile");
    if (isDefault_sampleFromPriorOnly)
        paramsNotSpecified.push_back("sampleFromPriorOnly");
    if (isDefault_initializeModel)
        paramsNotSpecified.push_back("initializeModel");
    if (isDefault_runMCMC)
        paramsNotSpecified.push_back("runMCMC");
    if (isDefault_updateBetaScale)
        paramsNotSpecified.push_back("updateBetaScale");
    if (isDefault_updateNodeStateScale)
        paramsNotSpecified.push_back("updateNodeStateScale");
    if (isDefault_betaInit)
        paramsNotSpecified.push_back("betaInit");
    if (isDefault_updateBetaShiftScale)
        paramsNotSpecified.push_back("updateBetaShiftScale");
    if (isDefault_updateEventRateScale)
        paramsNotSpecified.push_back("updateEventRateScale");
    if (isDefault_betaShift)
        paramsNotSpecified.push_back("betaShift");
    if (isDefault_localGlobalMoveRatio)
        paramsNotSpecified.push_back("localGlobalMoveRatio");
    if (isDefault_targetNumber)
        paramsNotSpecified.push_back("targetNumber");
    if (isDefault_betaInitPrior)
        paramsNotSpecified.push_back("betaInitPrior");
    if (isDefault_betaShiftPrior)
        paramsNotSpecified.push_back("betaInitPrior");
    if (isDefault_useObservedMinMaxAsTraitPriors)
        paramsNotSpecified.push_back("useObservedMinMaxAsTraitPriors");
    if (isDefault_traitPriorMin)
        paramsNotSpecified.push_back("traitPriorMin");
    if (isDefault_traitPriorMax)
        paramsNotSpecified.push_back("traitPriorMax");
    if (isDefault_mcmcOutfile)
        paramsNotSpecified.push_back("mcmcOutfile");
    if (isDefault_eventDataOutfile)
        paramsNotSpecified.push_back("eventDataOutfile");
    if (isDefault_betaOutfile)
        paramsNotSpecified.push_back("betaOutfile");
    if (isDefault_nodeStateOutfile)
        paramsNotSpecified.push_back("nodeStateOutfile");
    if (isDefault_acceptrateOutfile)
        paramsNotSpecified.push_back("acceptRateOutfile");
    if (isDefault_treeWriteFreq)
        paramsNotSpecified.push_back("treeWriteFreq");
    if (isDefault_eventDataWriteFreq)
        paramsNotSpecified.push_back("eventDataWriteFreq");
    if (isDefault_mcmcWriteFreq)
        paramsNotSpecified.push_back("mcmcWriteFreq");
    if (isDefault_acceptWriteFreq)
        paramsNotSpecified.push_back("acceptWriteFreq");
    if (isDefault_printFreq)
        paramsNotSpecified.push_back("printFreq");
    if (isDefault_NGENS)
        paramsNotSpecified.push_back("NumberGenerations");
    if (isDefault_updateRateEventNumber)
        paramsNotSpecified.push_back("updateRateEventNumber");
    if (isDefault_updateRateEventRate)
        paramsNotSpecified.push_back("updateRateEventRate");
    if (isDefault_updateRateEventPosition)
        paramsNotSpecified.push_back("updateRateEventPosition");
    if (isDefault_updateRateBeta0)
        paramsNotSpecified.push_back("updateRateBeta0");
    if (isDefault_updateRateBetaShift)
        paramsNotSpecified.push_back("updateRateBetaShift");
    if (isDefault_updateRateNodeState)
        paramsNotSpecified.push_back("updateRateNodeState");
    if (isDefault_initialNumberEvents)
        paramsNotSpecified.push_back("initialNumberEvents");
    if (isDefault_loadEventData)
        paramsNotSpecified.push_back("loadEventData");
    if (isDefault_eventDataInfile)
        paramsNotSpecified.push_back("eventDataInfile");

    if (paramsNotSpecified.size() > 0) {
        std::cout << "\nPrinting parameters with default settings: " << std::endl << std::endl;

        for (std::vector<std::string>::size_type i = 0; i < paramsNotSpecified.size(); i++)
            std::cout << std::setw(25) << paramsNotSpecified[i] << std::endl;
        std::cout << "\nSome or all of these may be problematic, potentially resulting in fatal errors "
             << std::endl << std::endl;
    }



}


bool Settings::stringToBool(const char* x)
{
    bool bval;
    if (atoi(x) == 0)
        bval = false;
    else if (atoi(x) == 1)
        bval = true;
    else {
        std::cout << "Invalid boolean when initializing class Settings" << std::endl;
        throw;
    }
    return bval;
}


void Settings::printCurrentSettings_Diversification(bool printOnlyChangesToDefaults)
{

    int ppw = 29;

    std::cout << "*****************************************************" << std::endl;
    std::cout << "Current parameter settings: " << std::endl;
    if (printOnlyChangesToDefaults) {
        std::cout << "\tPrinting only changes to default settings" << std::endl;
        std::cout << std::endl;
        if (!isDefault_treefile)
            std::cout << std::right << std::setw(ppw) << "treefile" << "\t\t" << _treefile << std::endl;
        if (!isDefault_loadEventData)
            std::cout << std::right << std::setw(ppw) << "loadEventData" << "\t\t" << _loadEventData <<
                 std::endl;
        if (!isDefault_eventDataInfile)
            std::cout << std::right << std::setw(ppw) << "eventDataInfile" << "\t\t" << _eventDataInfile <<
                 std::endl;
        if (!isDefault_sampleFromPriorOnly)
            std::cout << std::right << std::setw(ppw) << "sampleFromPriorOnly" << "\t\t" <<
                 _sampleFromPriorOnly << std::endl;
        if (!isDefault_runMCMC)
            std::cout << std::right << std::setw(ppw) << "runMCMC" << "\t\t" << _runMCMC << std::endl;
        if (!isDefault_initializeModel)
            std::cout << std::right << std::setw(ppw) << "initializeModel" << "\t\t" << _initializeModel <<
                 std::endl;
        if (!isDefault_useGlobalSamplingProbability)
            std::cout << std::right << std::setw(ppw) << "useGlobalSamplingProbability" << "\t\t" <<
                 _useGlobalSamplingProbability << std::endl;
        if (!isDefault_sampleProbsFilename)
            std::cout << std::right << std::setw(ppw) << "sampleProbsFilename" << "\t\t" <<
                 _sampleProbsFilename << std::endl;
        if (!isDefault_globalSamplingFraction)
            std::cout << std::right << std::setw(ppw) << "globalSamplingFraction" << "\t\t" <<
                 _globalSamplingFraction << std::endl;
        if (!isDefault_updateLambdaInitScale)
            std::cout << std::right << std::setw(ppw) << "updateLambdaInitScale" << "\t\t" <<
                 _updateLambdaInitScale << std::endl;
        if (!isDefault_updateMuInitScale)
            std::cout << std::right << std::setw(ppw) << "updateMuInitScale" << "\t\t" <<
                 _updateMuInitScale << std::endl;
        if (!isDefault_updateLambdaShiftScale)
            std::cout << std::right << std::setw(ppw) << "updateLambdaShiftScale" << "\t\t" <<
                 _updateLambdaShiftScale << std::endl;
        if (!isDefault_updateMuShiftScale)
            std::cout << std::right << std::setw(ppw) << "updateMuShiftScale" << "\t\t" <<
                 _updateMuShiftScale << std::endl;
        if (!isDefault_lambdaInit0)
            std::cout << std::right << std::setw(ppw) << "lambdaInit0" << "\t\t" << _lambdaInit0 << std::endl;
        if (!isDefault_lambdaShift0)
            std::cout << std::right << std::setw(ppw) << "lambdaShift0" << "\t\t" << _lambdaShift0 << std::endl;
        if (!isDefault_muInit0)
            std::cout << std::right << std::setw(ppw) << "muInit0" << "\t\t" << _muInit0 << std::endl;
        if (!isDefault_muShift0)
            std::cout << std::right << std::setw(ppw) << "muShift0" << "\t\t" << _muShift0 << std::endl;
        if (!isDefault_updateEventRateScale)
            std::cout << std::right << std::setw(ppw) << "updateEventRateScale" << "\t\t" <<
                 _updateEventRateScale << std::endl;
        if (!isDefault_localGlobalMoveRatio)
            std::cout << std::right << std::setw(ppw) << "localGlobalMoveRatio" << "\t\t" <<
                 _localGlobalMoveRatio << std::endl;
        if (!isDefault_targetNumber)
            std::cout << std::right << std::setw(ppw) << "targetNumber" << "\t\t" << _targetNumber << std::endl;
        if (!isDefault_lambdaInitPrior)
            std::cout << std::right << std::setw(ppw) << "lambdaInitPrior" << "\t\t" << _lambdaInitPrior <<
                 std::endl;
        if (!isDefault_lambdaShiftPrior)
            std::cout << std::right << std::setw(ppw) << "lambdaShiftPrior" << "\t\t" << _lambdaShiftPrior
                 << std::endl;
        if (!isDefault_muInitPrior)
            std::cout << std::right << std::setw(ppw) << "muInitPrior" << "\t\t" << _muInitPrior << std::endl;
        if (!isDefault_muShiftPrior)
            std::cout << std::right << std::setw(ppw) << "muShiftPrior" << "\t\t" << _muShiftPrior << std::endl;
        if (!isDefault_updateEventLocationScale)
            std::cout << std::right << std::setw(ppw) << "updateEventLocationScale" << "\t\t" <<
                 _updateEventLocationScale << std::endl;
        if (!isDefault_segLength)
            std::cout << std::right << std::setw(ppw) << "segLength" << "\t\t" << _segLength << std::endl;
        if (!isDefault_mcmcOutfile)
            std::cout << std::right << std::setw(ppw) << "mcmcOutfile" << "\t\t" << _mcmcOutfile << std::endl;
        if (!isDefault_lambdaOutfile)
            std::cout << std::right << std::setw(ppw) << "lambdaOutfile" << "\t\t" << _lambdaOutfile <<
                 std::endl;
        if (!isDefault_muOutfile)
            std::cout << std::right << std::setw(ppw) << "muOutfile" << "\t\t" << _muOutfile << std::endl;
        if (!isDefault_acceptrateOutfile)
            std::cout << std::right << std::setw(ppw) << "acceptrateOutfile" << "\t\t" <<
                 _acceptrateOutfile << std::endl;
        if (!isDefault_lambdaNodeOutfile)
            std::cout << std::right << std::setw(ppw) << "lambdaNodeOutfile" << "\t\t" <<
                 _lambdaNodeOutfile << std::endl;
        if (!isDefault_treeWriteFreq)
            std::cout << std::right << std::setw(ppw) << "treeWriteFreq" << "\t\t" << _treeWriteFreq <<
                 std::endl;
        if (!isDefault_mcmcWriteFreq)
            std::cout << std::right << std::setw(ppw) << "mcmcWriteFreq" << "\t\t" << _mcmcWriteFreq <<
                 std::endl;
        if (!isDefault_eventDataWriteFreq)
            std::cout << std::right << std::setw(ppw) << "eventDataWriteFreq" << "\t\t" <<
                 _eventDataWriteFreq << std::endl;
        if (!isDefault_acceptWriteFreq)
            std::cout << std::right << std::setw(ppw) << "acceptWriteFreq" << "\t\t" << _acceptWriteFreq <<
                 std::endl;
        if (!isDefault_printFreq)
            std::cout << std::right << std::setw(ppw) << "printFreq" << "\t\t" << _printFreq << std::endl;
        if (!isDefault_NGENS)
            std::cout << std::right << std::setw(ppw) << "NGENS" << "\t\t" << _NGENS << std::endl;
        if (!isDefault_updateRateEventNumber)
            std::cout << std::right << std::setw(ppw) << "updateRateEventNumber" << "\t\t" <<
                 _updateRateEventNumber << std::endl;
        if (!isDefault_updateRateEventPosition)
            std::cout << std::right << std::setw(ppw) << "updateRateEventPosition" << "\t\t" <<
                 _updateRateEventPosition << std::endl;
        if (!isDefault_updateRateEventRate)
            std::cout << std::right << std::setw(ppw) << "updateRateEventRate" << "\t\t" <<
                 _updateRateEventRate << std::endl;
        if (!isDefault_updateRateLambda0)
            std::cout << std::right << std::setw(ppw) << "updateRateLambda0" << "\t\t" <<
                 _updateRateLambda0 << std::endl;
        if (!isDefault_updateRateLambdaShift)
            std::cout << std::right << std::setw(ppw) << "updateRateLambdaShift" << "\t\t" <<
                 _updateRateLambdaShift << std::endl;
        if (!isDefault_updateRateMu0)
            std::cout << std::right << std::setw(ppw) << "updateRateMu0" << "\t\t" << _updateRateMu0 <<
                 std::endl;
        if (!isDefault_updateRateMuShift)
            std::cout << std::right << std::setw(ppw) << "updateRateMuShift" << "\t\t" <<
                 _updateRateMuShift << std::endl;
        if (!isDefault_initialNumberEvents)
            std::cout << std::right << std::setw(ppw) << "initialNumberEvents" << "\t\t" <<
                 _initialNumberEvents << std::endl;
        if (!isDefault_minCladeSizeForShift)
            std::cout << std::right << std::setw(ppw) << "minCladeSizeForShift" << "\t\t" <<
                 _minCladeSizeForShift << std::endl;
        if (!isDefault_seed)
            std::cout << std::right << std::setw(ppw) << "seed" << "\t\t" <<
                 _seed << std::endl;

    } else {
        std::cout << "\tPrinting ALL parameter settings " << std::endl;
        std::cout << std::endl;
        std::cout << std::right << std::setw(ppw) << "treefile" << "\t\t" << _treefile << std::endl;
        std::cout << std::right << std::setw(ppw) << "sampleFromPriorOnly" << "\t\t" <<
             _sampleFromPriorOnly << std::endl;
        std::cout << std::right << std::setw(ppw) << "runMCMC" << "\t\t" << _runMCMC << std::endl;
        std::cout << std::right << std::setw(ppw) << "initializeModel" << "\t\t" << _initializeModel <<
             std::endl;
        std::cout << std::right << std::setw(ppw) << "useGlobalSamplingProbability" << "\t\t" <<
             _useGlobalSamplingProbability << std::endl;
        std::cout << std::right << std::setw(ppw) << "sampleProbsFilename" << "\t\t" <<
             _sampleProbsFilename << std::endl;
        std::cout << std::right << std::setw(ppw) << "eventDataInfile" << "\t\t" << _eventDataInfile <<
             std::endl;
        std::cout << std::right << std::setw(ppw) << "globalSamplingFraction" << "\t\t" <<
             _globalSamplingFraction << std::endl;
        std::cout << std::right << std::setw(ppw) << "updateLambdaInitScale" << "\t\t" <<
             _updateLambdaInitScale << std::endl;
        std::cout << std::right << std::setw(ppw) << "updateMuInitScale" << "\t\t" <<
             _updateMuInitScale << std::endl;
        std::cout << std::right << std::setw(ppw) << "updateLambdaShiftScale" << "\t\t" <<
             _updateLambdaShiftScale << std::endl;
        std::cout << std::right << std::setw(ppw) << "updateMuShiftScale" << "\t\t" <<
             _updateMuShiftScale << std::endl;
        std::cout << std::right << std::setw(ppw) << "lambdaInit0" << "\t\t" << _lambdaInit0 << std::endl;
        std::cout << std::right << std::setw(ppw) << "lambdaShift0" << "\t\t" << _lambdaShift0 << std::endl;
        std::cout << std::right << std::setw(ppw) << "muInit0" << "\t\t" << _muInit0 << std::endl;
        std::cout << std::right << std::setw(ppw) << "muShift0" << "\t\t" << _muShift0 << std::endl;
        std::cout << std::right << std::setw(ppw) << "updateEventRateScale" << "\t\t" <<
             _updateEventRateScale << std::endl;
        std::cout << std::right << std::setw(ppw) << "localGlobalMoveRatio" << "\t\t" <<
             _localGlobalMoveRatio << std::endl;
        std::cout << std::right << std::setw(ppw) << "targetNumber" << "\t\t" << _targetNumber << std::endl;
        std::cout << std::right << std::setw(ppw) << "lambdaInitPrior" << "\t\t" << _lambdaInitPrior <<
             std::endl;
        std::cout << std::right << std::setw(ppw) << "lambdaShiftPrior" << "\t\t" << _lambdaShiftPrior
             << std::endl;
        std::cout << std::right << std::setw(ppw) << "muInitPrior" << "\t\t" << _muInitPrior << std::endl;
        std::cout << std::right << std::setw(ppw) << "muShiftPrior" << "\t\t" << _muShiftPrior << std::endl;
        std::cout << std::right << std::setw(ppw) << "updateEventLocationScale" << "\t\t" <<
             _updateEventLocationScale << std::endl;
        std::cout << std::right << std::setw(ppw) << "segLength" << "\t\t" << _segLength << std::endl;
        std::cout << std::right << std::setw(ppw) << "mcmcOutfile" << "\t\t" << _mcmcOutfile << std::endl;
        std::cout << std::right << std::setw(ppw) << "lambdaOutfile" << "\t\t" << _lambdaOutfile <<
             std::endl;
        std::cout << std::right << std::setw(ppw) << "muOutfile" << "\t\t" << _muOutfile << std::endl;
        std::cout << std::right << std::setw(ppw) << "acceptrateOutfile" << "\t\t" <<
             _acceptrateOutfile << std::endl;
        std::cout << std::right << std::setw(ppw) << "lambdaNodeOutfile" << "\t\t" <<
             _lambdaNodeOutfile << std::endl;
        std::cout << std::right << std::setw(ppw) << "treeWriteFreq" << "\t\t" << _treeWriteFreq <<
             std::endl;
        std::cout << std::right << std::setw(ppw) << "eventDataWriteFreq" << "\t\t" <<
             _eventDataWriteFreq << std::endl;
        std::cout << std::right << std::setw(ppw) << "mcmcWriteFreq" << "\t\t" << _mcmcWriteFreq <<
             std::endl;
        std::cout << std::right << std::setw(ppw) << "acceptWriteFreq" << "\t\t" << _acceptWriteFreq <<
             std::endl;
        std::cout << std::right << std::setw(ppw) << "printFreq" << "\t\t" << _printFreq << std::endl;
        std::cout << std::right << std::setw(ppw) << "NGENS" << "\t\t" << _NGENS << std::endl;
        std::cout << std::right << std::setw(ppw) << "updateRateEventNumber" << "\t\t" <<
             _updateRateEventNumber << std::endl;
        std::cout << std::right << std::setw(ppw) << "updateRateEventPosition" << "\t\t" <<
             _updateRateEventPosition << std::endl;
        std::cout << std::right << std::setw(ppw) << "updateRateEventRate" << "\t\t" <<
             _updateRateEventRate << std::endl;
        std::cout << std::right << std::setw(ppw) << "updateRateLambda0" << "\t\t" <<
             _updateRateLambda0 << std::endl;
        std::cout << std::right << std::setw(ppw) << "updateRateLambdaShift" << "\t\t" <<
             _updateRateLambdaShift << std::endl;
        std::cout << std::right << std::setw(ppw) << "updateRateMu0" << "\t\t" << _updateRateMu0 <<
             std::endl;
        std::cout << std::right << std::setw(ppw) << "updateRateMuShift" << "\t\t" <<
             _updateRateMuShift << std::endl;
        std::cout << std::right << std::setw(ppw) << "initialNumberEvents" << "\t\t" <<
             _initialNumberEvents << std::endl;
        std::cout << std::right << std::setw(ppw) << "minCladeSizeForShift" << "\t\t" <<
             _minCladeSizeForShift << std::endl;
        std::cout << std::right << std::setw(ppw) << "seed" << "\t\t" <<
             _seed << std::endl;

    }


    std::cout << std::endl;

    std::cout << "*****************************************************" << std::endl;




}



void Settings::parseCommandLineInput(int argc, std::vector<std::string>& instrings)
{

    std::vector<std::string> badFlags;

    for (std::vector<std::string>::size_type i = 0; i < (std::vector<std::string>::size_type)argc; i++) {
        if (instrings[i] == "-control") {
            if (instrings.size() == ( i - 1)){
                std::cout << "Error: no controfile specified" << std::endl;
                std::cout << "Exiting\n\n" << std::endl;
            }
            std::string controlfile = instrings[i + 1];
            std::cout << "\n\nInitializing BAMM using control file <<" << controlfile << ">>" <<
                 std::endl;
            std::ifstream instream(controlfile.c_str());
            if (!instream) {
                std::cout << "File not found error: cannot locate control file in\n";
                std::cout <<  "specified directory. Exiting BAMM" << std::endl << std::endl;
                exit(1);
            } else {
                initializeSettingsDevel(controlfile);
            }

        } else {
            if (i != 0) {
                // If i == 0, we just assume that this is either (i) the path to the executable
                //  or (ii), the commands used to invoke it.
                //  May depend on system/compiler, but first argument should
                //  not be a valid flag...
                badFlags.push_back(instrings[i]);
            }
 
        }
    }

    if (areAllParametersSetToDefaults()) {
        std::cout << "Failed to initialize parameter values\nExiting BAMM" << std::endl;
        exit(1);
    }
}







