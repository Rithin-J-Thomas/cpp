WORKS ONLY IF VALID INPUTS ARE GIVEN. SOME VALIDATIONS ARE IN PLACE, BUT COVERED MOST USER INPUT VALIDATIONS


Future enhancements
==================
- Could add feature to check time and date if passed or not

    // // for getting the current time & date of system
    void Current_Time()
    {
        std::time_t time_stamp = std::time(nullptr);  // // gets time stamp of current time
        std::cout << std::ctime(&time_stamp);         // // just print in the readable form
    }

