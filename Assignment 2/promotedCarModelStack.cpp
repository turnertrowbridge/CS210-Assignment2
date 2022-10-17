#include "promotedCarModelStack.h"

#include <utility>

/**
 * I the undersigned promise that the submitted assignment is my own work. While I was
 * free to discuss ideas with others, the work contained is my own. I recognize that
 * should this not be the case; I will be subject to penalties as outlined in the course
 * syllabus.
 * Name: Turner Trowbridge
 * Red ID: 827959204
 */

/**
   * @brief push operation, pushing the latest promoted model onto the stack
            Both time and auxiliary space complexity need to be O(1) 
   * @param model 
   * @param price 
   */
void PromotedCarModelStack::push(string model, int price) {
        //push latestModel onto stack
        PromotedModel latestModel = PromotedModel(model, price);
        latestPromotedModelStack.push_front(latestModel);

        //if the list is empty, make a pair of the one and only latestModel
        if (maxMinList.empty()){
            maxMinList.push_front(make_pair(latestModel, latestModel));

        //check if the price of the latestModel is greater than the max of the top of maxMinList
        // if true, push latestModel as max, and use old min from last model
        }else if (price > maxMinList.front().first.getPromotedPrice()) {
            maxMinList.push_front(make_pair(latestModel, maxMinList.front().second));

        //check if the price of the latestModel is less than the min of the top of maxMinList
        // if true, push latestModel as min, and use old max from last model
        } else if (price < maxMinList.front().second.getPromotedPrice()) {
            maxMinList.push_front(make_pair(maxMinList.front().first, latestModel));

        //if neither a max nor min price
        // push the old max and min models to maxMinList
        } else {
            maxMinList.push_front(make_pair(maxMinList.front().first, maxMinList.front().second));
        }
}

/**
   * @brief pop operation, popping the latest promoted model off the stack
            Both time and auxiliary space complexity need to be O(1) 
   * @param  
   * @return PromotedModel
   */
PromotedModel PromotedCarModelStack::pop() {
    //throw exception if stack is empty
    if (latestPromotedModelStack.empty()) {
        throw logic_error("Promoted car model stack is empty");
    }

    //save latestModel and remove top of latestPromotedModelStack
    // also remove the top node from maxMinList that accompanies the latestPromotedModelStack
    PromotedModel latestModel = latestPromotedModelStack.front();
    latestPromotedModelStack.pop_front();
    maxMinList.pop_front();
    return latestModel;
}

/**
   * @brief peek operation, peeking the latest promoted model at the top of the stack (without popping)
            Both time and auxiliary space complexity need to be O(1) 
   * @param 
   * @return PromotedModel
   */
PromotedModel PromotedCarModelStack::peek() {
    //throw exception if stack is empty
    if (latestPromotedModelStack.empty()) {
        throw logic_error("Promoted car model stack is empty");
    }

    //peek at the latestModel
    PromotedModel latestModel = latestPromotedModelStack.front();
    return latestModel;
}

/**
   * @brief getHighestPricedPromotedModel, 
   *        getting the highest priced model among the past promoted models
            Both time and auxiliary space complexity need to be O(1)
   * @param 
   * @return PromotedModel
   */
PromotedModel PromotedCarModelStack::getHighestPricedPromotedModel() {
    //throw exception if stack is empty
    if (latestPromotedModelStack.empty()) {
        throw logic_error("Promoted car model stack is empty");
    }

    //get highest priced model which is stored at front of maxMinList in first pair slot
    PromotedModel highestPricedModel = maxMinList.front().first;

    return highestPricedModel;
}

/**
   * @brief getLowestPricedPromotedModel, 
   *        getting the lowest priced model among the past promoted models
            Both time and auxiliary space complexity need to be O(1)
   * @param 
   * @return PromotedModel
   */
PromotedModel PromotedCarModelStack::getLowestPricedPromotedModel() {
    //throw exception if stack is empty
    if (latestPromotedModelStack.empty()) {
        throw logic_error("Promoted car model stack is empty");
    }

    //get lowest priced model which is stored at front of maxMinList in second pair slot
    PromotedModel lowestPricedModel = maxMinList.front().second;

    return lowestPricedModel;
}