include_directories(../include)

add_library(tinyxml2 tinyxml2.cpp)

add_executable(states states.cpp)
target_link_libraries(states PRIVATE tinyxml2)

add_executable(users users.cpp)
target_link_libraries(users PRIVATE tinyxml2)

add_executable(merchants merchants.cpp)
target_link_libraries(merchants PRIVATE tinyxml2)

add_executable(credit_card credit_card.cpp)
target_link_libraries(credit_card PRIVATE tinyxml2)

add_executable(credit_card_user credit_card_user.cpp)
target_link_libraries(credit_card_user PRIVATE tinyxml2)