#include "promotedCarModelStack.h"

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
        latestPromotedModelList.push_front(latestModel);

        //compare latestModel to saved highs and lows on highAndLowPromotedList and
        // push front if greater than saved high, push back if less than saved low
        if (highAndLowPromotedModelList.size() == 0){
            highAndLowPromotedModelList.push_front(latestModel);
        }else if (price >= highAndLowPromotedModelList.front().getPromotedPrice()) {
            highAndLowPromotedModelList.push_front(latestModel);
        } else if (price <= highAndLowPromotedModelList.back().getPromotedPrice()) {
            highAndLowPromotedModelList.push_back((latestModel));
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
    if (latestPromotedModelList.empty()) {
        throw logic_error("Promoted car model stack is empty");
    }

    // save latestModel and pop
    PromotedModel latestModel = latestPromotedModelList.front();
    latestPromotedModelList.pop_front();

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
    if (latestPromotedModelList.empty()) {
        throw logic_error("Promoted car model stack is empty");
    }

    //peek at the latestModel
    PromotedModel latestModel = latestPromotedModelList.front();
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
    if (latestPromotedModelList.empty()) {
        throw logic_error("Promoted car model stack is empty");
    }

    //get highest priced model which is stored at front
    PromotedModel highestPricedModel = highAndLowPromotedModelList.front();
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
    if (latestPromotedModelList.empty()) {
        throw logic_error("Promoted car model stack is empty");
    }

    //get lowest priced model which is stored at back
    PromotedModel lowestPricedModel = highAndLowPromotedModelList.back();
    return lowestPricedModel;
}