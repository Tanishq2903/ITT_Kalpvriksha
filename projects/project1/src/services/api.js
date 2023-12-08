import axios from "axios";
export const categoryMovies = async(API_URL) => {
    try {
        let response = axios.get(API_URL);
        return (await response).data;
    } catch (error) {
        console.log('Error while calling api',error.message);
        return error.response.data;
    }
}