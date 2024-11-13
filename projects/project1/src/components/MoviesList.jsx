import { Box, List, ListItem, Typography,styled } from "@mui/material";
import { Star } from "@mui/icons-material";

const Banner = styled('img')({
    width: 47
})
const Container = styled(List)`
display: flex
`

const MoviesList = ({movies}) => {
    return(

        <>
            {
                movies.map(movie => {
                   <Container>
                    <ListItem>
                        <Banner src = {`https://image.tmdb.org/t/p/original/${movie.poster_path}`}alt = "poster"/>
                    </ListItem>
                    <ListItem>
                        <Typography>{movie.orginal_title}</Typography>
                    </ListItem>
                    <ListItem>
                        <Star color="warning"/>
                        <Typography>{movie.vote_average}</Typography>
                    </ListItem>
                    <Typography>
                        {movie.release_date}
                    </Typography>
                   </Container>
                })
            }
        </>
    )
}
export default MoviesList;