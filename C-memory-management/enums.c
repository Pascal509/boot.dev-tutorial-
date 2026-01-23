// You can define a new enum type like this:
/*
An enum is not a collection type like a struct or an
array. It's just a list of integers constrained to a new type, where each is given an explicit name.
*/

#include "http.h"


typedef enum DaysOfWeek {
  MONDAY,
  TACO_TUESDAY,
  WEDNESDAY,
  THURSDAY,
  FRIDAY,
  SATURDAY,
  FUNDAY,
} days_of_week_t;

// How to Use Enums

typedef struct Event {
  char *title;
  days_of_week_t day;
} event_t;

// Or if you don't want to use the alias:

typedef struct Event {
  char *title;
  enum DaysOfWeek day;
} event_t;

// If you want to set those enumerations to specific values

typedef enum {
  EXIT_SUCCESS = 0,
  EXIT_FAILURE = 1,
  EXIT_COMMAND_NOT_FOUND = 127,
} ExitStatus;



// Switch Cases

/*
One of the best features of enums is that it can be used in switch
statements. Enums + switch statements:

Avoid "magic numbers"
Use descriptive names
With modern tooling, will give you an error/warning that you haven't
handled all the cases in your switch
*/


char *http_to_str(http_error_code_t code) {
switch(code) {
  case HTTP_BAD_REQUEST:
    return "400 Bad Request";

  case HTTP_UNAUTHORIZED:
    return "401 Unauthorized";

  case HTTP_NOT_FOUND:
    return "404 Not Found";

  case HTTP_TEAPOT:
    return "418 I AM A TEAPOT!";

  case HTTP_INTERNAL_SERVER_ERROR:
    return "500 Internal Server Error";
  default:
    return "Unknown HTTP status code";
  }
}